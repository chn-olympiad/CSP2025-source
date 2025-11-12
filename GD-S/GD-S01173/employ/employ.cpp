#include<bits/stdc++.h>
using namespace std;
const long long mod=998224353;
long long n,m,e[505],c[505],sum,ans,f[505];
bool flag=true,v[505];
string s;
void dfs(int k){
	if(k==n+1){
		long long cnt=0,cntans=0;
		for(int i=1;i<=n;i++){
			if(cnt>=f[i]){
				cnt++;
				continue;
			}
			if(!e[i]){
				cnt++;
				continue;
			}
			cntans++;
		}
		if(cntans>=m) ans++;
		ans=ans%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			f[k]=c[i];
			dfs(k+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		e[i+1]=s[i]-'0';
		if(!e[i+1]) flag=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]) sum++;
	}
	if(flag){
		ans=1;
		for(int i=1;i<=sum;i++){
			ans=ans*i;
			ans=ans%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
