#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int p=1e9+7;
map<ull,int> mp;
vector<ull> g[2020];
ull h1[2020],h2[2020],p2[2020];
string s1[200020],s2[200020];
void init(string ss1,string ss2)
{
    for (int i=1;i<ss1.size();i++) h1[i]=h1[i-1]*p+ss1[i];
    for (int i=1;i<ss2.size();i++) h2[i]=h2[i-1]*p+ss2[i];
}
ull find1(int l,int r)
{
    return h1[r]-h1[l-1]*p2[r-l+1];
}
ull find2(int l,int r)
{
    return h2[r]-h2[l-1]*p2[r-l+1];
}
struct node
{
    int l,r;
};
vector<node> h[5000050];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin >>n>>q;
    for (int i=1;i<=n;i++) cin >>s1[i]>>s2[i];
    if(n<=1000&&q<=1000)
    {
        int cur=0;
        p2[0]=1;
        for (int i=1;i<=2000;i++) p2[i]=p2[i-1]*p;
        for (int i=1;i<=n;i++)
        {
            s1[i]='?'+s1[i];
            s2[i]='?'+s2[i];
            ull hh1=0,hh2=0;
            for (int j=1;j<s1[i].size();j++) hh1=hh1*p+s1[i][j];
            for (int j=1;j<s2[i].size();j++) hh2=hh2*p+s2[i][j];
            if(!mp[hh1]) mp[hh1]=++cur;
            g[mp[hh1]].push_back(hh2);
            //cout<<hh1<<" "<<hh2<<endl;
        }
        while(q--)
        {
            string ss1,ss2;
            cin >>ss1>>ss2;
            ss1='?'+ss1;
            ss2='?'+ss2;
            init(ss1,ss2);
            int k=ss1.size()-1,ans=0;
            if(ss1.size()!=ss2.size())
            {
                cout<<"0\n";
                continue;
            }
            for (int i=1;i<=k;i++)
            {
                if(find1(1,i-1)!=find2(1,i-1)) continue;
                for (int j=k;j>=i;j--)
                {
                    if(find1(j+1,k)!=find2(j+1,k)) break;
                    ull x=find1(i,j),z=find2(i,j);
                    //cout<<i<<" "<<j<<" "<<x<<" "<<z<<endl;
                    for (auto y:g[mp[x]])
                    {
                        if(y==z) ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        int l1=0,l2=0,x;
        s1[i]='?'+s1[i];
        s2[i]='?'+s2[i];
        for (int j=1;j<s1[i].size();j++)
        {
            if(s1[i][j]=='b') l1=j;
            if(s2[i][j]=='b') l2=j;
        }
        if(l1>l2) x=l1+n-l2;
        else x=l2-l1;
        h[x].push_back({l1-1,n-l2+1});
    }
    while(q--)
    {
        string ss1,ss2;
        cin >>ss1>>ss2;
        ss1='?'+ss1;
        ss2='?'+ss2;
        if(ss1.size()!=ss2.size())
        {
            cout<<"0\n";
            continue;
        }
        int l1,l2,x,ans=0;
        for (int i=1;i<ss1.size();i++)
        {
            if(ss1[i]=='b') l1=i;
            if(ss2[i]=='b') l2=i;
        }
        if(l1>l2) x=l1+n-l2;
        else x=l2-l1;
        for (auto y:h[x])
        {
            if(y.l<=l1&&y.r<=n-l2+1) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
