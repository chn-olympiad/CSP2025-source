#include<bits/stdc++.h>
#define For(i,a,b)for(int i=a;i<=b;i++)
using namespace std;
inline int read(void){
    register int x=0,f=1;
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
inline void write(int x){
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
const int N=105;
int R,n,m,a[N];
bool cmp(const int& a,const int& b){
    return a>b;
}
int ksc(int a,int b){
    if(b==0) return 0;
    int z=ksc(a,b>>1);
    z=z+z;
    if(b&1) z=z+a;
    return z;
}
int Find(int q){
    int l=1,r=ksc(n,m);
    while(l<r){
        int mid=(l+r)>>1;
        if(a[mid]<q){
            r=mid;
        }else if(a[mid]>q){
            l=mid+1;
        }else return mid;
    }
    return -1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read(),m=read();
    For(i,1,ksc(n,m)){
        a[i]=read();
    }
    R=a[1];
    sort(a+1,a+1+ksc(n,m),cmp);
    int f=Find(R);
    int ms=f/n,ns=f%n;
    if(ns==0){
        write(ms);
        putchar(' ');
        if(!(ms&1)) write(1);
        else write(n);
    }
    else if(ns!=0) {
        ms++;
        write(ms);
        putchar(' ');
        if(!(ms&1)){
            write(n-ns+1);
        }else write(ns);
    }
    return 0;
}
