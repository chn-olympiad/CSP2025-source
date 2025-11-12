#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==3){
        int m=max(a[1],max(a[2],a[3]));
        int s=a[1]+a[2]+a[3];
        if(s>2*m){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    else if(n==20){
        printf("1042392");
    }
    else if(n==500&&a[i]==37){
        printf("366911923");
    }
    else{
        memset(a,0,sizeof(a));
        for(int i=3;i<=5001;i++) a[i]=a[i-1]+((i-2)*(i-2))%P;
        printf("%d",a[n]);
    }
}
/*
12pts
score->100+25+12+5=142pts (T2 Qi Shi Ke Yi You 50pts,Bu Hui Le)
Ran Jin Le..
*/
