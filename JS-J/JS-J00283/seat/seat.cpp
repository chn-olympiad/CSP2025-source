#include<bits/stdc++.h>
using namespace std;
int n,m;
int s,t;
int c,r;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[1]) t++;
    }
    t++;//Maths
    c=(t+n-1)/n;
    r=(c%2==1)?(t-1)%n+1:n-(t-1)%n;
    printf("%d %d",c,r);
    return 0;
}
