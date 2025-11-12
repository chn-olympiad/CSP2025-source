#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int a[N];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,R,s;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;++i) scanf("%lld",&a[i]);
    R=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;++i){
        if(a[i]==R){
            s=i;
            break;
        }
    }
    int r=1,c=1,dr=1,dc=0;
    if(n==1){
        printf("%lld %lld",s,1);
        return 0;
    }
    for(int i=1;i<s;++i){
        r+=dr;
        c+=dc;
        if(r==n&&dr==1&&dc==0) dr=0,dc=1;
        else if(r==1&&dr==-1&&dc==0) dr=0,dc=1;
        else if(dr==0&&dc==1&&c%2==0) dr=-1,dc=0;
        else if(dr==0&&dc==1&&c%2==1) dr=1,dc=0;
    }
    printf("%lld %lld",c,r);
    return 0;
}
