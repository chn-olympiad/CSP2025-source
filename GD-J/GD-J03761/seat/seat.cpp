#include <bits/stdc++.h>
using namespace std;
long long a[11*11];
long long b[11][11];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    scanf("%lld",&a[1]);
    long long target=a[1];
    for(long long i=2;i<=n*m;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n*m+1,cmp);
    long long i=1,j=1,xb=1;
    bool up=0;
    while(1){
        b[i][j]=a[xb++];
        if(b[i][j]==target){
            printf("%lld %lld",j,i);
            break;
        }
        if(up){
            i--;
        }else{
            i++;
        }
        if(i>n){
            i--;
            j++;
            up=1;
        }
        if(i<1){
            i++;
            j++;
            up=0;
        }
    }
}
