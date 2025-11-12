//xor.cpp
#include<bits/stdc++.h>
using namespace std;
const long long N=500010;
long long a[N],ans,sum,k;
int n;
bool pd;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            sum=a[i];
            for(int k=i+1;k<=j;k++){
                sum|=a[i];
                if(a[i]==-1){
                    pd=true;
                    break;
                }
            }
            if(sum==k&&!pd){
                ans++;
                fill(a+i,a+i+j,-1);
            }
            pd=false,sum=0;
    }
    printf("%lld\n",ans);
    return 0;
}
