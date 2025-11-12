#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[506],c[506],b[506];
string s;
void dfs(long long x){
	if(x==n+1){
		long long rs=0,q=0;
		for(long long i=1;i<=n;i++) 
			if(s[i-1]=='0'||rs>=c[a[i]]) rs++;
			else q++;
		ans+=(q>=m);
		return;
	}
	for(long long i=1;i<=n;i++)
		if(!b[i]) a[x]=i,b[i]=1,dfs(x+1),a[x]=b[i]=0;
}
long long pd(){
	for(long long i=0;i<s.size();i++)
		if(s[i]=='0') return 0;
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	long long sl=0;
	for(long long i=1;i<=n;i++) cin>>c[i],sl+=(c[i]==0);
	if(n-sl<m){
		cout<<0;
		return 0;
	}
	if(n==m){
		if(pd()) cout<<0;
		else{
			ans=1;
			for(long long i=1;i<=n;i++) ans*=i,ans%=998244353;
			cout<<ans;
		}
		return 0;
	}
	if(n<=10) dfs(1);
	cout<<ans;
	return 0;
} 