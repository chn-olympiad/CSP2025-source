#include<bits/stdc++.h>
using namespace std;
void fff(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
}
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int n,m,tgt;
int a[1005];
int st[55][55];
int cnt=1;
int main(){
    fff();
    n=read(),m=read();
    tgt=a[1]=read();
    for(int i=2;i<=n*m;i++){
        a[i]=read();
    }
    sort(a+1,a+1+n*m,greater<int>());
    for(int j=1;j<=m;j+=2){
        for(int i=1;i<=n;i++){
            st[i][j]=a[cnt++];
        }
        for(int i=n;i>=1;i--){
            st[i][j+1]=a[cnt++];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(st[i][j]==tgt){
                printf("%d %d\n",j,i);
                return 0;
            }
        }
    }
    return 0;
}
