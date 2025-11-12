#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
const int maxm=1.1e7+5,maxn=4e5+5;
const int mod1=998244353,base1=127;
const int mod2=1e9+7,base2=129;
int n,q,ans[maxn],power1[maxm],power2[maxm];
pair<int,int> hsh1[maxn],hsh2[maxn];
string s,t;
vector<long long> upd[maxm];
vector<pair<long long,int>> qry[maxm];
map<pair<long long,long long>,int> mp;
int Tree[maxm][26],tot;
vector<int> nbr[maxm];
long long gethsh1(int l,int r)
{
    int val1=hsh1[r].first-1ll*hsh1[l-1].first*power1[r-l+1]%mod1;
    int val2=hsh1[r].second-1ll*hsh1[l-1].second*power2[r-l+1]%mod2;
    val1=(val1+mod1)%mod1,val2=(val2+mod2)%mod2;
    return 1ll*val1*mod2+val2;
}
long long gethsh2(int l,int r)
{
    int val1=hsh2[r].first-1ll*hsh2[l-1].first*power1[r-l+1]%mod1;
    int val2=hsh2[r].second-1ll*hsh2[l-1].second*power2[r-l+1]%mod2;
    val1=(val1+mod1)%mod1,val2=(val2+mod2)%mod2;
    return 1ll*val1*mod2+val2;
}
void insert(int x,string &s,long long val)
{
    for(int i=0;i<s.size();i++)
    {
        int c=s[i]-'a';
        if(Tree[x][c]==0) Tree[x][c]=++tot;
        x=Tree[x][c];
    }
    // cout<<x<<" "<<s<<" "<<val<<"!!\n";
    upd[x].push_back(val);
}
void insert(int x,string &s,vector<pair<long long,int>> &val)
{
    for(int i=0;i<s.size();i++)
    {
        int c=s[i]-'a';
        if(Tree[x][c]==0) Tree[x][c]=++tot,nbr[x].push_back(Tree[x][c]);
        x=Tree[x][c];
    }
    for(auto X:val) qry[x].push_back(X);
}
void solveupd()
{
    for(int i=1;i<=n;i++)
    {
        int len=0;
        cin>>s>>t,len=s.size(),s=" "+s,t=" "+t;
        if(s==t) continue;
        for(int i=1;i<=len;i++)
        {
            hsh1[i].first=(1ll*hsh1[i-1].first*base1+s[i])%mod1;
            hsh1[i].second=(1ll*hsh1[i-1].second*base2+s[i])%mod2;
        }
        for(int i=1;i<=len;i++)
        {
            hsh2[i].first=(1ll*hsh2[i-1].first*base1+t[i])%mod1;
            hsh2[i].second=(1ll*hsh2[i-1].second*base2+t[i])%mod2;
        }
        int lt,rt,l=0,r=len+1;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(gethsh1(1,mid)==gethsh2(1,mid)) l=mid;
            else r=mid;
        }
        lt=r,l=0,r=len+1;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(gethsh1(mid,len)==gethsh2(mid,len)) r=mid;
            else l=mid;
        }
        rt=l;
        // cout<<lt<<" "<<rt<<" "<<gethsh1(len,len)<<" "<<gethsh2(len,len)<<"\n";
        string S;
        for(int i=lt-1;i>=1;i--) S+=s[i];
        long long val=gethsh1(rt+1,len);
        pair<long long,long long> P={gethsh1(lt,rt),gethsh2(lt,rt)};
        if(mp[P]==0) mp[P]=++tot;
        insert(mp[P],S,val);
    }
}
void solveqry()
{
    for(int i=1;i<=q;i++)
    {
        int len=0;
        cin>>s>>t,len=s.size(),s=" "+s,t=" "+t;
        for(int i=1;i<=len;i++)
        {
            hsh1[i].first=(1ll*hsh1[i-1].first*base1+s[i])%mod1;
            hsh1[i].second=(1ll*hsh1[i-1].second*base2+s[i])%mod2;
        }
        for(int i=1;i<=len;i++)
        {
            hsh2[i].first=(1ll*hsh2[i-1].first*base1+t[i])%mod1;
            hsh2[i].second=(1ll*hsh2[i-1].second*base2+t[i])%mod2;
        }
        int lt,rt,l=0,r=len+1;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(gethsh1(1,mid)==gethsh2(1,mid)) l=mid;
            else r=mid;
        }
        lt=r,l=0,r=len+1;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(gethsh1(mid,len)==gethsh2(mid,len)) r=mid;
            else l=mid;
        }
        rt=l;
        string S;
        for(int i=lt-1;i>=1;i--) S+=s[i];
        vector<pair<long long,int>> val;
        for(int k=rt;k<=len;k++) val.push_back({gethsh1(rt+1,k),i});
        pair<long long,long long> P={gethsh1(lt,rt),gethsh2(lt,rt)};
        if(mp[P]==0) continue;
        insert(mp[P],S,val);
    }
}
bool vis[maxm];
gp_hash_table<long long,int> tmp;
void solve(int cur)
{
    vis[cur]=1;
    for(auto x:upd[cur]) tmp[x]++;
    for(auto [x,id]:qry[cur])
    {
        ans[id]+=tmp[x];
        // if(id==1) cout<<"!"<<x<<"\n";
    }
    for(int i=0;i<26;i++)
        if(Tree[cur][i]!=0) solve(Tree[cur][i]);
    for(auto x:upd[cur]) tmp[x]--;
}
int main()
{
    frepoen("replace.in","r",stdin);
    frepoen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q,power1[0]=power2[0]=1;
    for(int i=1;i<maxm;i++) power1[i]=1ll*power1[i-1]*base1%mod1;
    for(int i=1;i<maxm;i++) power2[i]=1ll*power2[i-1]*base2%mod2;
    solveupd(),solveqry();
    for(int i=1;i<=tot;i++)
        if(vis[i]==0) solve(i);
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}