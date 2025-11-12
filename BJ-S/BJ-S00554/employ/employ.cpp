#include<bits/stdc++.h>
using namespace std;

int n,ans=0,a[510],f[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
        for(int i=1;i<=n;i++){char ch;cin>>ch;}
        for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
            if(a[i-1]==a[i]) f[i]=f[i-1]+1,ans+=f[i];
    cout<<ans+1;
    return 0;
}
