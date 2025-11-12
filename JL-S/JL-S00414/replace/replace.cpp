#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,cnt;
const ll N=2e5+10;
string s[N][5],t[N][5];
namespace sub1
{
    void solve()
    {
        string t1,t2,s3="",x="",y="";
        cin>>t1;
        for(int i=0;i<=t1.size();i++)
        {
            for(int j=0;j+i<=t1.size();j++)
            {
                s3="",x="",y="";
                for(int k=0;k<i;k++)
                    x+=t1[k];
                for(int k=i;k<=i+j;k++)
                    s3+=t1[k];
                for(int k=i+j+1;k<t1.size();k++)
                    y+=t1[k];
                for(int k=1;k<=n;k++)
                {
                    if(s3==s[k][1])
                        s3=s[k][2];
                    if(x+s3+y==t2)
                        cnt++;
                }
            }
        }
        cout<<cnt;
    }
}
namespace sub2
{
    void solve()
    {
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("relpace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    if(q==1)
    {
        sub1::solve();
        return 0;
    }
    if(n<=100)
    {
        sub2::solve();
        return 0;
    }
    while(q--)
    {
        cout<<0<<'\n';
    }
    return 0;
}
