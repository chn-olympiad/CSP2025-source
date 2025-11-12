#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;cin>>n>>k;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    b[0]=0;b[1]=a[1];
    for(int i=2;i<=n;i++)
        b[i]=a[i]^b[i-1];


    int ans=0,began=1;
    for(int i=1;i<=n;i++){
        for(int j=began;j<=i;j++){
            if(int(b[j-1]^b[i])==k){
                ans++;began=i+1;break;
            }
        }
    }
    cout<<ans;
    return 0;
}
