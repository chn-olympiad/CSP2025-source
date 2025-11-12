#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,flag=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*flag;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x<10){
        putchar(x+48);
        return;
    }
    write(x/10);
    putchar(x%10+48);
}
bool cmp(int x,int y){
    return x>y;
}
int n,m,a[504][505],s[505];
int ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n*m;++i) s[i]=read();
    ans=s[1];
    sort(s+1,s+n*m+1,cmp);
    int temp=0;
    for(int j=1;j<=m;++j){
        if(j&1){
            for(int i=1;i<=n;++i){
                a[i][j]=s[++temp];
                if(a[i][j]==ans){
                    write(j);
                    putchar(' ');
                    write(i);
                    putchar('\n');
                    return 0;
                }
            }
        }else{
            for(int i=n;i>=1;--i) {
                a[i][j]=s[++temp];
                if(a[i][j]==ans){
                    write(j);
                    putchar(' ');
                    write(i);
                    putchar('\n');
                    return 0;
                }
            }
        }
    }
    return 0;
}
