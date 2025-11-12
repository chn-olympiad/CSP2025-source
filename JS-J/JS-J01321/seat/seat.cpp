#include<bits/stdc++.h>
using namespace std;
int n,m,a[666],x,y,id,cnt=0,f=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    x=a[1];
    sort(a+1,a+n*m+1);
    for (int i=1;i<=n*m;i++) if (a[i]==x) id=n*m-i+1;
    x=1,y=1;
    for (;;){
        ++cnt;
        if (cnt==id) break;
        if (f==0){
            ++x;
            if (x==n) f=1;
        }
        else if (f==1){
            ++y;
            f=2;
        }
        else if (f==2){
            --x;
            if (x==1) f=3;
        }
        else{
            ++y;
            f=0;
        }
    }
    printf("%d %d\n",y,x);
    return 0;
}
