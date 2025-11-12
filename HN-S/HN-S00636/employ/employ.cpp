#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,m,c[N],s[N],a[N],v[N],ans;
void dfs(int x){
	if(x-1==n){
		int num=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				num++;
				continue;
			}
			if(num>=c[a[i]]){
				num++;
				continue;
			}
		}
		ans+=(n-num>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		a[x]=i;
		v[i]=1;
		dfs(x+1);
		v[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
		f=(f&s[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)f=0;
	}
	if(m==n){
		if(!f)cout<<"0";
		else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%mod;
			}
			cout<<ans;
		}
		return 0;
	}
		dfs(1);
	cout<<ans;
	return 0;
}

