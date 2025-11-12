#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef __int128 lint;
const int mx=5e3+5;
const ll MOD=998244353;
int n;
int a[mx];
ll ans;
inline bool check(lint i){
    int maxn=0;
    int sum=0;
    int cnt=0;
    for(int j=0;j<n;j++){
        if(1<<j&i){
            maxn=max(maxn,a[j+1]);
            sum+=a[j+1];
            cnt++;
        }
    }
    if(sum>2*maxn && cnt>=3) return true;
    else return false;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(lint i=0;i<1<<n;i++){
        if(check(i)) ans=(ans+1)%MOD;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
