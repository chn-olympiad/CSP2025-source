#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,cnt,c[N];
unsigned long long ans=1,ans2=1;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        if(c[i]==0)cnt++;
    }
    int x=m-cnt;
    if(cnt>n-m)cout<<0<<endl;
    for(int i=n;i>=1;i--)
    {
        ans=ans*i%998244353;
    }
    for(int i=x;i>=1;i--)
    {
        ans2=ans2*i%998244353;
    }
    if(ans2>ans)cout<<ans2-ans<<endl;
    else cout<<ans-ans2<<endl;

}
