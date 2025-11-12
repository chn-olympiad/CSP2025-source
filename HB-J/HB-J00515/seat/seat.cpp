#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
ll n,m,cnt=1,x,y,ans1=1,ans2=0;
bool flag=0;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read<ll>();
    m=read<ll>();
    x=read<ll>();
    for(ll i=2;i<=n*m;i++){
        y=read<ll>();
        if(y>x) cnt++;
    }
    while(cnt>n){
        cnt-=n;
        flag=!flag;
        ans1++;
    }
    if(flag){
        ans2=n-cnt+1;
    }
    else{
        ans2=cnt;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
