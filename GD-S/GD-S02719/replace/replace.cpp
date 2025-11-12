#include<bits/stdc++.h>
#define N 1000005
#define ll long long
#define mod 998244353
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
ll n,m,k,jk,ans,sum,num,cnt,tot,base=13;
ll head[N],dis[N],vis[N],wis[N],kis[N][2],f[N][2];
string A[N][2],a,b;
unordered_map<int,bool> p,p1;

void read(ll & x){
	x=0;ll ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));
}

int ksm(int x,int y){
	int z=1;while(y){
		if(y&1) z=z*x%mod;
		x=x*x%mod;y>>=1;
	}return z;
}

ll Get(ll x,ll y){
	return ((dis[y]-ksm(base,y-x+1)*dis[x-1]%mod)%mod+mod)%mod;
}

ll Get1(ll x,ll y){
	return ((vis[y]-ksm(base,y-x+1)*vis[x-1]%mod)%mod+mod)%mod;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(m);
	for(ll i=1;i<=n;i++){
		cin>>A[i][0]>>A[i][1];
		ll X=0,Y=0;
		for(ll j=0;j<(ll)A[i][0].size();j++){
			X=((X*base)+(A[i][0][j]-'a'+1))%mod;
			Y=((Y*base)+(A[i][1][j]-'a'+1))%mod;
		}kis[i][0]=X;kis[i][1]=Y;p[X]=1;p1[Y]=1;
//		wk(X),wh(Y);
	}
	while(m--){
		cin>>a>>b;a=' '+a;b=' '+b;
		ll n=(ll)a.size()-1;
		for(ll j=1;j<=n;j++){
			dis[j]=((dis[j-1]*base)+(a[j]-'a'+1))%mod;
			vis[j]=((vis[j-1]*base)+(b[j]-'a'+1))%mod;
		}f[n+1][0]=f[n+1][1]=0;
		for(ll j=n;j>=1;j--){
			f[j][0]=((f[j+1][0]*base)+(a[j]-'a'+1))%mod;
			f[j][1]=((f[j+1][1]*base)+(b[j]-'a'+1))%mod;
		}
		for(ll i=1;i<=n;i++){
			if(dis[i-1]!=vis[i-1]) continue;
			for(ll j=i;j<=n;j++){
				if(f[j+1][0]!=f[j+1][1]) continue;
				int X=Get(i,j),Y=Get1(i,j);
//				wk(i),wk(j),wk(X),wh(Y);
				if(!p[X]||!p1[Y]) continue;
				for(int p=1;p<=n;p++){
					if(kis[p][0]==X&&kis[p][1]==Y) ans++;
				}
			}
		}wh(ans);ans=0;
	}
	return 0;
}
