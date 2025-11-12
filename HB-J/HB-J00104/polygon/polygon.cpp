#include<bits/stdc++.h>
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
inline long long read(void){
    register long long x=0,f=1;
    register char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            f=-f;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void write(long long x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x<=9){
        putchar(x+'0');
        return;
    }else{
        write(x/10);
        putchar(x%10+'0');
    }
}
const int N=5005,M=998244353;
long long n,a[N],ans;
struct node{
    int l,r;
    int sum,maxn;
    node(){
        l=r=sum=maxn=0;
    }
    void init(int p){
        l=r=p;
        sum=a[p];
        maxn=a[p];
    }
}z[N<<2];
node operator+(const node&l,const node&r){
    node res;
    res.l=l.l;
    res.r=r.r;
    res.sum=l.sum+r.sum;
    res.maxn=max(l.maxn,r.maxn);
    return res;
}
void build(int l,int r,int rt){
    if(l==r){
        z[rt].init(l);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    z[rt]=z[rt<<1]+z[rt<<1|1];
}
node query(int l,int r,int rt,int nowl,int nowr){
    if(nowl>=l&&nowr<=r){
        return z[rt];
    }
    int m=(l+r)>>1;
    if(l<=m){
        if(r>m) return query(lson,nowl,nowr)+query(rson,nowl,nowr);
        else return query(lson,nowl,nowr);
    }else return query(rson,nowl,nowr);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    build(root);
    for(int len=3;len<=n;len++){
        for(int i=1,j=i+len-1;j<=n;i++,j++){
            node opt=query(root,i,j);
            if(opt.sum>2*opt.maxn) ans=(ans+1)%M;
        }
    }
    write(ans);
    return 0;
}
