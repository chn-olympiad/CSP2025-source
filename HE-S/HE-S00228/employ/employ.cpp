#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>inline void read(T&x){
	x=0;char c;int sgin=1;
	do{
		c=getchar();
		if(c=='-')sgin=-1;
	}while(!isdigit(c));
	do{
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	}while(isdigit(c));
	x*=sgin;
}
const int mod=998244353;
int n,m,s[511],c[510],ans,p[510];
bool vis[510];

void dfs(int x){
	if(x==n+1){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(cnt2<c[p[i]]&&s[i]==1)cnt1++;
			else cnt2++;
		}
		if(cnt1>=m)ans++;
		ans%=mod;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=true;
				p[x]=i;
				dfs(x+1);
				vis[i]=false;
			}
		}
	}
}

void dfss(int x){
	if(x==n+1){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(cnt2<c[p[i]]&&s[i]==1)cnt1++;
			else cnt2++;
		}
		if(cnt1>=m)ans++;
		ans%=mod;
	}
	else{
		int cnt1=0,cnt2=0;
		for(int i=1;i<=x;i++){
			if(cnt2<c[p[i]]&&s[i]==1)cnt1++;
			else cnt2++;
			if(cnt2)return;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=true;
				p[x]=i;
				dfs(x+1);
				vis[i]=false;
			}
		}
	}
}

int qpow(int a,int b){
	int res=1;
	while(b!=0){
		if(b&1)res=res%mod*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);
	read(m);
	bool flag1=true;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		if(x=='0')s[i]=0,flag1=false;
		else s[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag1){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	else if(n<=26){
		dfs(1);
		cout<<ans;
	}
	else if(n==m){
		dfss(1);
		cout<<ans;
	}
	else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
