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
const int N=5*1e5+10;
int n,k,a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read(),k=read();
    For(i,1,n){
        a[i]=read();
    }
    write(k-n%k);
    return 0;
}
