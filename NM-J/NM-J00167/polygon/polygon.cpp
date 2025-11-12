#include <bits/stdc++.h>
using namespace std;

int n;
int m1,m2;
int a[10001];
int ma = 0;
int sum = 0;
int ans = 0;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    if(n < 3){
        printf("0");
        return 0;
    }
    ma = max(a[1],a[2]);
    ma = max(ma,a[3]);
    sum = a[1] + a[2] + a[3];
    if(sum >= ma*2){
        printf("1");
        return 0;
    }
    printf("0");
    return 0;
}
