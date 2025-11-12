#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],val,pos,x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    val=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==val) break;
        if(x%2==1) y++;
        else y--;
        if(y==m+1) x++,y--;
        if(y==0) x++,y++;
    }
    printf("%d %d",x,y);
    return 0;
}
