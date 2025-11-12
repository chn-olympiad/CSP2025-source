#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int k=1,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')k=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*k;
}
void print(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x<10){
        putchar(x+'0');
        return;
    }
    print(x/10);
    putchar(x%10+'0');
}
const int N=5e5+5;
int a[N];
struct node{
    int r,id;
}b[N];
bool cmp(node a,node b){
    return a.r<b.r;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    n=read();
    k=read();
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int xo=a[i];
        int r=i;
        while(xo!=k&&r<=n){
            r++;
            xo^=a[r];
            if(xo==k)break;
            if(i<=l&&r>=l)break;
        }
        if(xo==k&&r<=n&&!(i<=l&&r>=l)){
            if(i>l)ans++;
            l=r;
            b[i].r=r;
        }
        else b[i].r=LLONG_MAX;
        b[i].id=i;
    }
    print(ans);
    putchar('\n');
    return 0;
}