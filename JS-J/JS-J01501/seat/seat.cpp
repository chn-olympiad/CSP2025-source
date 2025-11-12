#include <bits/stdc++.h>
using namespace std;
int n,m;
int r;
int a[102];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m*n;i++)
        scanf("%d",&a[i]);
    r=a[1];
    int i=1;
    sort(a+1,a+1+n*m);
    for(i=n*m;i>=1;i--)
        if(a[i]==r)
            break;
    i=n*m-i+1;
    int sum=i;
    printf("%d ",sum/n+(sum%n!=0 ? 1 : 0));
    int ans=sum%(n*2);
    if(ans<=n)
        printf("%d",ans);
    else    
        printf("%d",2*n-ans+1);
    return 0;
}