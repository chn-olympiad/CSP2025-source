#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5005;
int a[N],can[N*N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n=0;
    int sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    can[0]=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int mx=a[i]+1;
        for(int j=mx;j<=sum;j++){
            cnt=(can[j]+cnt)%MOD;
        }
        for(int j=sum-a[i];j>=0;j--){
            can[j+a[i]]=(can[j+a[i]]+can[j])%MOD;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
