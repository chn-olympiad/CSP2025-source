#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define getchar getchar_unlocked
//#define putchar putchar_unlocked
namespace stdio_promax{
	inline void read(int& x){x=0;int f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}x*=f;}
	inline void read(ll& x){x=0;int f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}x*=f;}
	inline void write(int x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10^48);}
	inline void write(ll x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10^48);}
}
using namespace stdio_promax;
const int N=510,mod=998244353;
int n,m,c[N];
bitset<N>b,book;
void read_str(){
    char ch=getchar();
    while(ch!='0'&&ch!='1')ch=getchar();
    for(int i=1;i<=n;i++){
        b[i]=ch-'0';
        ch=getchar();
    }
}
int ans=0;
void dfs(int now,int officer){
    if(now==n+1){
        if(officer>=m)ans++;
        ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!book[i]){
            book[i]=1;
            if(!b[now]||(now-1)-officer>=c[i])dfs(now+1,officer);
            else dfs(now+1,officer+1);
            book[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    read(n);read(m);
    read_str();
    for(int i=1;i<=n;i++){
        read(c[i]);
    }
    dfs(1,0);
    write(ans);
    putchar('\n');
	return 0;
}
