#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define umap1 unordered_map<ull,int>
using namespace std;
int n,q;
map<pair<ull,ull>,unordered_map<ull,umap1 > > cnt; 
map<pair<ull,ull>,unordered_map<ull,vector<pair<int,int> > > > ops;
const ull base=131;
const int N=2e5+10,M=5e6+10;
mt19937 rnd(1);
ull pw[M],w[26];
inline int rd(int l,int r)
{
    return abs((int)rnd())%(r-l+1)+l;
}
void init(int n)
{
    w[0]=rd(5,100);
    for(int i=1;i<26;i++) w[i]=w[i-1]+rd(5,100);
    pw[0]=1;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*base;
}
inline ull gt(ull s[],int l,int r)
{
    return s[r]-s[l-1]*pw[r-l+1];
}
ull hs1[M],hs2[M];
void gt_hs(string &s,ull hs[])
{
    for(int i=1;i<sz(s);i++) hs[i]=hs[i-1]*base+w[s[i]-'a'];
}
int solve()
{
    string t1,t2;
    cin>>t1>>t2;
    int m=sz(t1);
    if(sz(t1)!=sz(t2)) return 0;
    t1='0'+t1,t2='0'+t2;
    gt_hs(t1,hs1),gt_hs(t2,hs2);
    int l,r;
    for(int i=1;i<=m;i++)
    {
        if(t1[i]!=t2[i])
        {
            l=i;
            break;
        }
    }
    for(int i=m;i>=1;i--)
    {
        if(t1[i]!=t2[i])
        {
            r=i;
            break;
        }
    }
    int ans=0;
    for(int i=1;i<=l;i++)
    {
        umap1 &s=cnt[{gt(hs1,l,r),gt(hs2,l,r)}][gt(hs1,i,l-1)];
        if(!sz(s)) continue;
        //for(int j=r;j<=m;j++) ans+=s[gt(hs1,r+1,j)];
        if(s.count(gt(hs1,r+1,m))) ans+=s[gt(hs1,r+1,m)];
        else
        {
            int L=r,R=m,anss=r;
            while(L<=R)
            {
                int mid=L+R>>1;
                if(s.count(gt(hs1,r+1,mid))) anss=mid,L=mid+1;
                else R=mid-1;
            }
            ans+=s[gt(hs1,r+1,anss)];
        }
    }
    return ans;
}
string s1[N],s2[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    init(5e6);
    
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        if(s1[i]==s2[i]) continue;
        int m=sz(s1[i]);
        s1[i]='0'+s1[i],s2[i]='0'+s2[i];
        int l=0,r=0;
        for(int j=1;j<=m;j++)
        {
            if(s1[i][j]!=s2[i][j])
            {
                l=j;break;
            }
        }
        for(int j=m;j>=1;j--)
        {
            if(s1[i][j]!=s2[i][j])
            {
                r=j;
                break;
            }
        }
        gt_hs(s1[i],hs1),gt_hs(s2[i],hs2);
        vector<pair<int,int> > &s=ops[{gt(hs1,l,r),gt(hs2,l,r)}][gt(hs1,1,l-1)];
        s.pb(m-r+1,i);
    }
    for(auto o1:ops)
    {
        for(auto o2:o1.second)
        {
            vector<pair<int,int> > &s=o2.second;
            sort(all(s));
            for(auto o3:s) 
            {
                int i=o3.second;
                int m=sz(s1[i])-1;
                int l=0,r=0;
                for(int j=1;j<=m;j++)
                {
                    if(s1[i][j]!=s2[i][j])
                    {
                        l=j;break;
                    }
                }
                for(int j=m;j>=1;j--)
                {
                    if(s1[i][j]!=s2[i][j])
                    {
                        r=j;
                        break;
                    }
                }
                gt_hs(s1[i],hs1),gt_hs(s2[i],hs2);
                umap1 &ss=cnt[o1.first][o2.first];
                if(!ss.count(0)) ss[0]=0;
                for(int j=r;j<=m;j++) 
                {
                    ull hss=gt(hs1,r+1,j);
                    if(ss.count(hss)) continue;
                    ss[hss]=ss[gt(hs1,r+1,j-1)];
                }
                ss[gt(hs1,r+1,m)]++;
            }
        }
    }
    while(q--) cout<<solve()<<"\n";
    return 0;
}