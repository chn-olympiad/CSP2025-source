#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,a[N],x,f[15][15],tx,ty,cnt;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]);
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    tx=ty=1;
    while(++cnt<=n*m){
        f[tx][ty]=cnt;
        if(ty%2&&tx!=n)
            tx++;
        else if(ty%2&&tx==n)
            ty++;
        else if(ty%2==0&&tx!=1)
            tx--;
        else if(ty%2==0&&tx==1)
            ty++;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[f[i][j]]==x){
                printf("%d %d\n",j,i);
                return 0;
            }
    return 0;
}
