#include<bits/stdc++.h>
#define int long long
#define N 1000
using namespace std;
struct Node{int id,v;}a[N+5];
int n,m,ax,ay;
int read(){
    int f=1,g=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        g=g*10+ch-'0';
        ch=getchar();
    }
    return f*g;
}
void print(int x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return;
}
bool cmp(Node x,Node y){
    return x.v>y.v;
}
main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n*m;i++)a[i].v=read(),a[i].id=i;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            ay=(i-1)/n+1,ax=i-(ay-1)*n;
            if(ay%2==0)ax=n-ax+1;
            break;
        }
    }
    print(ay),putchar(' '),print(ax);//,putchar('\n');
    return 0;
}