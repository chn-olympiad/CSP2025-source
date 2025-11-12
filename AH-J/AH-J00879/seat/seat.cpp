#include<bits/stdc++.h>
using namespace std;
#define sp putchar(' ')
#define el putchar('\n')
using ll=__int128;
inline ll read(){
    ll x=0;
    int f=1;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^'0');
    }while(isdigit(cc=getchar()));
    return f*x;
}
inline void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x^'0');
    }else{
        print(x/10);
        putchar(x%10^'0');
    }
}
int a[105],seat[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=read(),m=read(),r;
    for(int i=1;i<=n*m;++i){
        a[i]=read();
    }
    r=a[1];
    sort(a+1,a+n*m+1,[](int x,int y){return x>y;});
    int id=lower_bound(a+1,a+n*m+1,r,[](int x,int y){return x>y;})-a;
    int col=(id+n-1)/n,lin=(id-1)%n+1;
    if((col&1)^1){
        lin=n+1-lin;
    }
    print(col);
    sp;
    print(lin);
    el;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

