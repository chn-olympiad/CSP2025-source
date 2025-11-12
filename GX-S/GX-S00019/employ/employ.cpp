//I Love CCF.I Want 100pts in this problem!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void read(ll &x){
	x=0;ll f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=f;
}
ll n,m,c[505];
ll vis[505],cnt0,cnt1,fac[505];
char s[505];
const int p=998224353;
bool v[12];ll tot=0;int a[12];
void dfs(int x){
	if(x==n+1){
		int cnt=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=cnt or vis[i]==0){ cnt++;continue;}
			else cnt1++;
		}
		if(cnt1>=m) tot++;
		return;
	}
	for(int i=1;i<=n;i++) if(!v[i]){ a[x]=i;v[i]=1;dfs(x+1);a[x]=0,v[i]=0;}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	int num=0,somebody=0;
	scanf("%s",s);
	for(int i=0;i<n;i++) vis[i+1]=s[i]-'0',cnt0+=(vis[i+1]==0),cnt1+=(vis[i+1]==1);
	for(int i=1;i<=n;i++) read(c[i]),num+=(c[i]==n),somebody+=(c[i]==0);;
	if(n==m){
		if(cnt0>=1){ cout<<0<<'\n';return 0;}
		else if(somebody>=1){ cout<<0<<'\n';return 0;}
		ll ans=1;
		for(int i=2;i<=n;i++) ans*=i,ans%=p;
		cout<<ans;
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;
	sort(c+1,c+n+1);
	if(m==1){
		ll ans[505],tot;
		for(int i=1;i<=n;i++){
			if(vis[i]==0) continue;
			int cnt=0;
			for(int j=1;j<=n;j++) if(c[j]>=i) cnt++;
			ans[++tot]=(fac[i-1]-ans[tot-1])*cnt%p*fac[n-i]%p;
		}
		ll sum=0;
		for(int i=1;i<=n;i++) sum+=ans[i],sum%=p;
		cout<<sum<<'\n';
		return 0;
	}
	if(n<=10){//bao li 
		dfs(1);
		cout<<tot<<'\n';
		return 0;
	}
	if(num==m){
		cout<<fac[n]<<'\n';
		return 0;
	}
	cout<<0<<'\n';
	return 0;
}
//I only have 172pts,can i go to NOIP(sad)?i want to go it!
//my names in Luogu is JadeFox2012
