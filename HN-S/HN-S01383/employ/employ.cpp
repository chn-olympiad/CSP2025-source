#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,z[505],s[505],fg[505],tmp,op=1,g;
long long fac[505],ans,sum,inv[505];
void dfs(int d,int cnt){
	if(cnt>=m){
		ans=(ans+fac[n-d+1])%mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(fg[i])continue;
		fg[i]=1;
		if(!z[d]||d-cnt-1>=s[i])dfs(d+1,cnt);
		else dfs(d+1,cnt+1);
		fg[i]=0;
	} 
	return;
}
int qpow(long long p,int q){
	int cnt=1;
	for(;q;q>>=1,p=p*p%mod)cnt=cnt*p%mod;
	return cnt;
}
int C(int p,int q){
	if(q<0||q>p)return 0;
	return fac[p]*inv[q]%mod*inv[p]%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;++i){
		char c;
		cin>>c;
		z[i]=c-'0';
		fac[i]=fac[i-1]*i%mod;
		op&=(z[i]==1);
		if(!tmp&&z[i])tmp=i;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i;--i)inv[i]=inv[i+1]*(i+1);
	for(int i=1;i<=n;++i)cin>>s[i],g+=(s[i]==0); 
	if(n<=18){
		dfs(1,0);
		cout<<ans; 
		return 0;
	}
	if(m==1){
		int cnt=0;
		sum=1;
		tmp=1;
		sort(s+1,s+n+1); 
		for(int i=1;i<=n;++i){
			if(z[i]){
				while(tmp<=n&&s[tmp]<i)++tmp;
				if(tmp>n)break;
				++cnt;
				ans=(ans+sum*fac[n-cnt]%mod*(n-tmp+1)%mod)%mod;
				sum=sum*C(n-cnt+1,tmp-1)%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		if(g==0&&op)cout<<fac[n];
		else cout<<'0';
		return 0;
	}
	if(op){
		if(n-g<=m)cout<<'0';
		else cout<<fac[n];
		return 0;
	}
	cout<<'0';
	return 0;
}
