#include <bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[105],r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    sum=n*m;
    for (int i=1;i<=sum;i++){
        scanf("%d",a+i);
    }
    r=a[1];
    sort(a+1,a+1+sum);
    int t=lower_bound(a+1,a+1+sum,r)-a;
    t=sum-t+1;
    int mod=t%n,line=t/n;
    if (mod==0){
        mod=n;
        line--;
    }
    if (line%2){
        mod=n-mod+1;
    }
    printf("%d %d",line+1,mod);
    return 0;
}
