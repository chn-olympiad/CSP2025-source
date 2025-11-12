#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int d,b;
}a[110];
bool cmp(node x,node y){
    return x.d>y.d;
}
int c[110],r[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i].d);
        a[i].b=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int w;
    for(int i=1;i<=n*m;i++){
        if(a[i].b==1){
                w=i;
                break;
        }
    }
    int sum=0;
    for(int i=1;i<=n*m;i+=n){
        sum++;
        for(int j=i;j<=n+i;j++){
            c[j]=sum;
        }
    }
    for(int i=1;i<=n*m;i+=n*2){
        for(int j=1;j<=n;j++){
            r[j+i-1]=j;
        }
    }
    for(int i=n+1;i<=n*m;i+=n*2){
        for(int j=1;j<=n;j++){
            r[j+i-1]=n-j+1;
        }
    }
    cout<<c[w]<<' '<<r[w]<<endl;
    return 0;
}