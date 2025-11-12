#include<bits/stdc++.h>
using namespace std;
int n,m,d,c;
struct Node{
    int d;
}a[105];
bool cmp(const Node &x,const Node &y){
    return x.d>y.d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i].d);
    }
    d=a[1].d;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].d==d){
            c=i;
            break;
        }
    }
    d=0;
    d=c/n+bool(c%n);
    c%=n;
    cout<<d<<" ";
    if(d%2) cout<<c;
    else cout<<n-c+1;
    return 0;
}
