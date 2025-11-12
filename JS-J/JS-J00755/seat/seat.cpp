#include<bits/stdc++.h>
using namespace std;
int a[102];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++)scanf("%d",a+i);
    int b=a[0];
    sort(a,a+n*m);
    int pos=n*m-(lower_bound(a,a+n*m,b)-a)-1;
    printf("%d ",pos/n+1);
    if(pos/n%2)printf("%d\n",n-pos%n);
    else printf("%d\n",pos%n+1);
    return 0;
}