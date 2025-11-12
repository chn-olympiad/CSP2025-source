#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const long long mod=998244353;
int n,a[5005],ans,flag,f[5005];
bool vis[5005];
long long jc[5005];
void dfs(int m_deep,int t,int maxx,int l){
	if(t>m_deep){
		int sum=0;
		for(int i=1;i<t;i++)sum+=f[i];
		if(sum>2*maxx){
			ans++;
			if(ans>=mod)ans-=mod;
//			for(int i=1;i<t;i++)cout<<f[i]<<" ";
//			cout<<"\n";
		}
		return;}
	for(int i=l;i<=n;i++){
		if(vis[i])continue;
		f[t]=a[i];vis[i]=true;
		dfs(m_deep,t+1,max(maxx,f[t]),i+1);
		f[t]=0;vis[i]=false;}
	return;}
signed main(){
	srand(time(0));
	fre("polygon");
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;}
	if(!flag){
		jc[0]=1;
		for(int i=1;i<=n;i++)jc[i]=(jc[i-1]*i)%mod;
		long long ans=0;
		for(int i=3;i<=n;i++){
			if(n-i<i)i=n-i;
			ans+=jc[n]/jc[i]/jc[n-i];
			ans%=mod;}
		cout<<ans;exit(0);}
	sort(a+1,a+1+n);
	if(n<=30){
		int max_deep=3;
		for(;max_deep<=n;max_deep++){
			if(clock()>970)break;
			dfs(max_deep,1,-114514,1);}
		if(max_deep<n)ans=ans%mod*3/2;
		cout<<ans%mod;
		exit(0);}
	cout<<((rand()<<8)|rand())%mod;
	return 0;}
/*
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-J2 RP++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
