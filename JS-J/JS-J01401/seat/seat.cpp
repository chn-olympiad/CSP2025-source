#include <bits/stdc++.h>

using namespace std;
int read();
void write(int x);
int n,m,a[120],R,t,l,h;
bool cmp(int x,int y);
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n*m;i++){
        a[i]=read();
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            t=i;
            break;
        }
    }

    l=(t-1)/n+1;
    if(l%2==1){
        h=(t-1)%n+1;
    }else{
        h=n-(t-1)%n;
    }
    write(l);
    putchar(' ');
    write(h);
    putchar('\n');
    return 0;
}
int read(){
    int x,y=1;char c;
    while((c=getchar())>'9'||c<'0') if(c=='-') y=-1;
    x=(c^48);
    while ((c=getchar())>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48);
    return x*y;
}
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
bool cmp(int x,int y){
    return x>y;
}
