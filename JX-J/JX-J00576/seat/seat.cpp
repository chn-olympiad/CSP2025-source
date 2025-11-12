#include<bits/stdc++.h>
using namespace std;
int cnt=1;
int a[120];
int x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[1])cnt++;
    }
    int a=floor(cnt/n)+1;
    int b=cnt%n;
    if(a%2==0)y=n-b+1,x=a;
    if(a%2!=0)y=b,x=a;
    if(y==0)y=n;
    cout<<x<<' '<<y;
    return 0;
}
