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
int a[105],r;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n*m;i++)a[i]=read();
    r=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int ansx=0,ansy=1;
    for(int i=1;i<=n*m;i++){
        if(ansy&1)ansx++;
        else ansx--;
        if(ansx>n||ansx<1){
            ansy++;
            if(ansy&1)ansx=1;
            else ansx=n;
        }
        if(a[i]==r)break;
    }
    cout<<ansy<<' '<<ansx<<endl;
    return 0;
}