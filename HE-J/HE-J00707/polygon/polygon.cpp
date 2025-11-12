#include <cstdio>
#include <algorithm>
using namespace std;

int a[5005];
int dp[5005][5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
        scanf("%d",&a[i]);
    sort(a,&a[n]);
    if(n<3){
        printf("0");
        return 0;
    }
    if(n==3){
        if(a[2]>a[0]+a[1])
            printf("1");
        else
            printf("0");
        return 0;

    }
    printf("%d",n-2);

    return 0;


}
