#include<bits/stdc++.h>
using namespace std;
const int A=998244353;
int a[5005],m,n,ans,lis[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    lis[1]=2;
    for(int i=2;i<=5000;i++){
        lis[i]=(lis[i-1]*2+2)%A;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[n+1]=0x3f3f3f3f;
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            int sum=a[i]+a[j];
            for(int k=j;k<n;k++){
                int hou=k-j;
                if(sum<=a[k+1]){
                    ans=(ans+lis[hou])%A;
                }
            }
       }
    }
    cout<<ans/2;
    fclose(stdin);
    fclose(stdout);
}
