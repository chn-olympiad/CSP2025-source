#include<bits/stdc++.h>

#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define Fol(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pi pair<int,int>
#define se second
#define fi first
#define ll long long
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

#define N 500005
#define mod 998244353

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9')f=(ch=='-'?-1:f),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x/10)write(x/10);
	putchar(x%10+'0');
}

void Add(int &x,int y){x=(x+y>=mod?x+y-mod:x+y);}
int pls(int x,int y){return x=(x+y>=mod?x+y-mod:x+y);}
void Dec(int &x,int y){x=(x-y<0?x-y+mod:x-y);}
int sub(int x,int y){return x=(x-y<0?x-y+mod:x-y);}
int mul(int x,int y){return x*1ll*y%mod;}
int qp(int x,int y=mod-2){int ans=1;while(y){if(y&1)ans=mul(ans,x);x=mul(x,x);y>>=1;}return ans;}

int fac[N],ifac[N];
int C(int x,int y){return mul(mul(fac[x],ifac[y]),ifac[x-y]);}
void init(){
	fac[0]=ifac[0]=1;
	For(i,1,N-1)fac[i]=mul(fac[i-1],i);
	ifac[N-1]=qp(fac[N-1]);
	Fol(i,N-2,1)ifac[i]=mul(ifac[i+1],i+1);
}

char s[N];
int c[N],coef[505][505];

namespace sub0{
	int sum[N],id[N];
	void solve(int n,int m){
		int ans=0;
		For(i,1,n)id[i]=i;
		do{
			int flag=1,las=0;
			For(i,1,n){
				if(i-las-1>=c[id[i]])flag=0;
				if(s[i]=='1')las=i;
			}
			ans+=flag;
		}while(next_permutation(id+1,id+n+1));
		write(ans);
	}
}



int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n=read(),m=read();init();
	scanf("%s",s+1);
	For(i,1,n)c[i]=read();
	if(n<=18)sub0::solve(n,m);
	
	return 0;
}
