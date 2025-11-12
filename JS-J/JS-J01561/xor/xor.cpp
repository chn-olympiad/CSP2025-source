#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long a[N],b[N];
long long  f[N][2];
int n,k;
int main()
{
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    f[0][1]=0;
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)f[i][0]++;
        f[i][0]+=max(f[i-1][0],f[i-1][1]);
       if(b[i-1]==k)f[i-1][1]--;
       if(a[i-1]==k)f[i-1][0]--;
       if((b[i-1]^a[i])==k)f[i-1][1]=f[i-1][1]+1;
       if((a[i-1]^a[i])==k)f[i-1][0]=f[i-1][0]+1;
       if(f[i-1][1]>=f[i-1][0])
       {
           f[i][1]=f[i-1][1];
           b[i]=(b[i-1]^a[i]);
       }
       else
       {
        f[i][1]=f[i-1][0];
       b[i]=(a[i-1]^a[i]);
       }
    }
    cout<<max(f[n][0],f[n][1])<<endl;
    return 0;
}
