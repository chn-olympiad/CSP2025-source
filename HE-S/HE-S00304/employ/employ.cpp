#include<bits/stdc++.h>
const int N=1e5+5;
#define int long long
using namespace std;
int ans;
int n,m;
int p[N],a[N];
string s;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)
    cin>>a[i],p[i]=i;
    do
    {
        int tot=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0')
            tot++;
            else
            {
                if(tot<a[p[i]])
                    sum++;
                else
                    tot++;
            } 
        }
        ans+=(sum>=m);
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
}