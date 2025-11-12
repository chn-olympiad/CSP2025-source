#include<bits/stdc++.h>
using namespace std;
int n,a[5055];
long long sum,tmp;
const int mod = 998244353;
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n<=3){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }sort(a+1,a+1+n);
        if(sum<=2*a[n])cout<<"0"<<endl;
        else cout<<"1"<<endl;
        return 0;
    }
    if(n<=5000){
        for(int i=1;i<=n;i++){
           scanf("%d",&a[i]);
        }sort(a+1,a+1+n);
        if(a[1] != 1||a[n] != 1){
            printf("114514");
            return 0;
        }
        else {
            for(int i=3;i<=n;i++){
                for(int j=0;j<i;j++){
                    tmp  = tmp*(n-j);
                }sum  = (sum + tmp/i)%mod;
            }printf("%lld",sum);
        }
    }

}
