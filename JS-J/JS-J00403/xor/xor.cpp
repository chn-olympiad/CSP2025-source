#include<bits/stdc++.h>
#define N 200100
using namespace std;
int n,k,a[N],ans,s[N];
bool vis[N];
inline int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') y=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*y;
}
inline void write(int x){
    if(!x) putchar('0');
    char F[200];
    if(x<0) putchar('-'),x=-x;
    int tmp=x,cnt=0;
    while(tmp>0){
        F[++cnt]=tmp%10+'0';
        tmp/=10;
    }
    while(cnt>0) putchar(F[cnt]),cnt--;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read();
    k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        for(int j=i+1;j<=n;j++){
            if(vis[j]) break;
            if((s[j]-s[i-1])%2==k){
                ans++;
                for(int k=i;k<=j;k++) vis[k]=1;
                break;
            }
        }
    }
    write(ans);
    return 0;
}
