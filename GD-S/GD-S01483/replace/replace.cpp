#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int read(){
    int res=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+(c-'0'),c=getchar();
    return res*f;
}
void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int maxn=2e4+100;
const int maxm=1e6+5;
const int mod=1e9+7;
int n,m;
void solve(){
    n=read(),m=read();
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int T=1;
    while(T--)solve();
    return 0;
}