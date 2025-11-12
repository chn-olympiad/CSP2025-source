#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
using namespace std;
#define int long long
typedef long long LL;
const int M=550;
const int mod=998244353;
int n,m,c[M],s[M],cnt[M],sum[M],t,ans;
bool b[M];
inline int read(){
	int ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}
LL jc(LL x){
	LL ans=1;
	For(i,1,x) ans=ans*i%mod;
	return ans;
}

void dfs(int k,int ct){
	//~ cout<<k<<" "<<ct<<endl;
	if(m>n-ct) return;
	if(k==n+1) {ans=(ans+1)%mod;return;}
	For(i,1,n){
		int ctt=ct;
		if(b[i]) continue;
		b[i]=1;
		if(ct>=c[i]||s[k]==0) ctt++;
		dfs(k+1,ctt);
		b[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	For(i,1,n) {
		s[i]=getchar_unlocked()-'0';
		while(s[i]!=0&&s[i]!=1) s[i]=getchar_unlocked()-'0';
	}
	For(i,1,n){c[i]=read();}
	
	if(m==1){
		t=n;
		queue<int> q;
		For(i,1,n) {
			cnt[c[i]]++;
			if(s[i]) q.push(i);
		}
		sum[0]=cnt[0],t=n-q.size();
		For(i,1,n) sum[i]=sum[i-1]+cnt[i];
		ans=1;
		int i=0;
		while(q.size()){
			int x=q.front();q.pop();
			ans=ans*(sum[x-1]-i)%mod;
			i++;
		}
		ans=ans*jc(t)%mod;
		cout<<(jc(n)+mod-ans)%mod;
		return 0;	
	}
	if(n==m){
		For(i,1,n) {
			if(s[i]==0||c[i]==0) {cout<<0;return 0;}
		}
		cout<<jc(n);
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
