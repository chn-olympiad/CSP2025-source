#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,r,l,fl;
vector<int>v;
inline int read(){
    int f=1,c=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){c=(c<<1)+(c<<3)+(ch^48);ch=getchar();}
    return c*f;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);cout.tie(0);
    n=read();m=read();
    for(int i=1;i<=n*m;i++)v.push_back(read());
    l=v[0];c=1,r=1,fl=1;
    sort(v.begin(),v.end());
    for(int i=n*m-1;i>=0;i--){
        if(v[i]==l){
            printf("%lld %lld",c,r);
            return 0;
        }
        if((r==1||r==n)&&fl==0)c++,fl=1;
        else r+=(c&1)?1:-1,fl=0;
    }
    return 0;
}