#include<bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n*m;i++){
        scanf("%d",&a[i]);
        cnt += (a[i]>=a[1]);
    }
    int h = ceil(1.0*cnt/n);
    printf("%d ",h);
    cnt -= (h-1)*n;
    if(h%2){
        printf("%d",cnt);
    } else{
        printf("%d",n-cnt+1);
    }
    return 0;
}
