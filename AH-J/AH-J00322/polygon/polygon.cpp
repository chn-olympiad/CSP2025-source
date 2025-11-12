//freopen
#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],f[5006],mod=998244353,sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i]+1;j<=5001;j++)sum=(sum+f[j])%mod;
        for(int j=5001;j>=0;j--){
            f[min(j+a[i],5001ll)]=(f[min(j+a[i],5001ll)]+f[j])%mod;
        }
    }
    cout<<sum;
    return 0;
}
//没活了，所以说数学期中考能不能多考点代数，少考点几何
//话说这次CSP好简单，一个小时多就已经写完了，希望能AK吧
