#include <bits/stdc++.h>
using namespace std;

int n,m,a[110],d,l;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]);
    l=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=n*m;j>=i+1;j--)
            if(a[j]>a[j-1]){
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        if(a[i]==l){
            d=i;
            break;
        }
    }
    if(d%n!=0)
        printf("%d %d",d/n+1,d%n);
    else
        printf("%d %d",d/n,n);
    return 0;
}
