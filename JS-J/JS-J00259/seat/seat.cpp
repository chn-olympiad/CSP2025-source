#include<bits/stdc++.h>
#define ll long long
#define u unsigned
using namespace std;
int n,m,a,s,t,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    s=n*m;
    scanf("%d",&t);
    for(int i=2;i<=s;i++){
        scanf("%d",&a);
        if(a>t)x++;
    }
    y=1+x/n;
    printf("%d ",y);
    x%=n;
    if(y%2==1)printf("%d",x+1);
    else printf("%d",n-x);
    return 0;
}
