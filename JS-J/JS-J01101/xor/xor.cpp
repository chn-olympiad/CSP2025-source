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
int n,k;
const int N=1e4+5;
int a[N];
struct node{
    int l,r;
}qj[N*N];
bool cmp(node x,node y){
    return x.r<y.r;
}
int cnt,s[N];
signed main(){
    //kouhu O(n^2) and ^qzh
    //please don't 0pts,give me 60pts
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read(),k=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    s[1]=a[1];
    for(int i=2;i<=n;++i) s[i]=s[i-1]^a[i];
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;j++){
            int t=s[j]^s[i-1];
            if(i==1) t=s[j];
            if(t==k){
                qj[++cnt].l=i,qj[cnt].r=j;
            }
        }
    }
    sort(qj+1,qj+cnt+1,cmp);
    int pos=0;
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(pos<qj[i].l){
            pos=qj[i].r;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
