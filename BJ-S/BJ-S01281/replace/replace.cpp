#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull base[5000010];
int n,q;
string s[200010][2];
int tot=0,nxt[20000010],head[10000010],ans[20000010]; ull var[20000010];
void add(ull x)
{
    int wz=x&((1<<20)-1);
    for(int i=head[wz]; i!=0; i=nxt[i])
    {
        if(var[i]==x) return ++ans[i],void();
    }
    var[++tot]=x,nxt[tot]=head[wz],head[wz]=tot,ans[tot]=1;
}
int get_ans(ull x)
{
    int wz=x&((1<<20)-1);
    for(int i=head[wz]; i!=0; i=nxt[i])
    {
        if(var[i]==x) return ans[i];
    }
    return 0;
}
map<ull,int> viscnt;
ull hsh[5000010];
ull get_hsh(int l,int r)
{
    return hsh[r]-(l==0?0:hsh[l-1])*base[r-l+1];
}
vector<int> len;
int main()
{
    //system("diff replace.out replace.ans");return 0;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    base[0]=1; for(int i=1; i<=5e6+5; ++i) base[i]=base[i-1]*13331;
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; ++i)
    {
        cin>>s[i][0]>>s[i][1];
        ull hsh=0;
        for(int j=0; j<s[i][0].size(); ++j)
        {
            hsh=hsh*13331+(s[i][0][j]-'a')*26+s[i][1][j]-'a'+1;
        }
        len.push_back(s[i][0].size());
        //++viscnt[hsh];
        add(hsh);
    }
    sort(len.begin(),len.end());
    len.erase(unique(len.begin(),len.end()),len.end());
    reverse(len.begin(),len.end());
    int cnt=0;
    while(q--)
    {
        string t0,t1; cin>>t0>>t1;
        int l=0,r=t0.size()-1;
        while(t0[l]==t1[l]) ++l;
        while(t0[r]==t1[r]) --r;
        for(int i=0; i<t0.size(); ++i)
        {
            hsh[i]=(i==0?0:hsh[i-1])*13331+(t0[i]-'a')*26+t1[i]-'a'+1;
        }
        long long ans=0;
        for(int i=0; i<=l; ++i)
        {
            ull nowhsh=get_hsh(i,l);
            for(int j:len)
            {
                if(j<r-i+1) break;
                ++cnt;
                if(i+j-1<t0.size()) ans+=get_ans(get_hsh(i,i+j-1));
            }
        }
        cout<<ans<<'\n';
    }
    //assert(cnt<=1e8);
    return 0;
}
