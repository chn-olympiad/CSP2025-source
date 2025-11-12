#include<bits/stdc++.h>
using namespace std;
long long n,m,c[100005],ans,t,a[10005],y,tt;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin>>n>>m>>s;
    for(long long i=0;i<n;i++)
    {
        cin>>c[i];
    }
    y=(n+1)*n/2;
    for(long long i=0;i<n;i++)a[i]=i+1;
    for(long long i=0;i<y;i++)
    {
        t=0;
        tt=0;
        for(long long j=0;j<n;j++)
        {
            if(s[i]=='0'||tt>=c[i])
            {
				tt++;
				continue;
			}
            t++;
        }
        next_permutation(a,a+n);
        if(t>=m)ans=(ans+1)%998244353;
    }
    cout<<ans;
    //if(t)ans=(ans*t)%998244353;
    return 0;
}
