#include<bits/stdc++.h>
using namespace std;
const int N=100+5;
int n,m,a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]);
    int R=a[1],pos=0;
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)
        if(a[i]==R){
            pos=i;
            break;
        }
    int c=(pos+n-1)/n,t=pos%n,r;
    if(t==0)
        t=n;
    if(c%2==1)
        r=t;
    else
        r=n+1-t;
    printf("%d %d",c,r);
    return 0;
}
