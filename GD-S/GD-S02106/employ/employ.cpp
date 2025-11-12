#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],lst[N],tot=0,vis[N],p[N],num[N],f[N],fac[N],inv[N];
char ch[N];
int ksm(int a,int b){
	int sum=1;
	while(b){
		if(b&1)sum=sum*a%mod;
		a=a*a%mod,b>>=1;
	}
	return sum;
}
int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return fac[n]*(inv[m]*inv[n-m]%mod)%mod;
} 
int ppp=0;
void dfs(int dep){
	if(dep==n){
		int sum=0,cc=0;
		for(int i=1;i<=n;i++){
			if(ch[i]=='0')cc++;
			else{
				if(c[p[i]]>cc)sum++;
				else cc++;
			}
		}
		if(sum>=m)ppp++;
		return;
	}
	dep++;
	for(int i=1;i<=n;i++)if(!vis[i])vis[i]=1,p[dep]=i,dfs(dep),vis[i]=0;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>n>>m>>ch+1;
	fac[0]=1;
	for(int i=1;i<=n;i++)cin >>c[i],num[c[i]]++,fac[i]=fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++)if(ch[i]=='1')lst[tot]=i,tot++;
	if(m==n){
		if(num[0]||tot!=n){
			cout <<"0";
			return 0;
		}
		cout <<fac[n];
		return 0;
	}
	dfs(0);
	cout <<ppp;
	return 0;
}

