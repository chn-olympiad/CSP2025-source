#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int inf=998244353;
int n,a[N];
long long ans;
int main(){
//    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int cnt=0;
    for(int i=1;i<=n-2;++i){
        cnt=a[i];
        for(int j=i+1;j<=n-1;++j){
            cnt+=a[j];
            for(int k=j+1;k<=n;++k){
                cnt+=a[k];
                if(a[k]*2<cnt){
                    ++ans;
                    ans%=inf;
                }
                //cnt-=a[k];
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
