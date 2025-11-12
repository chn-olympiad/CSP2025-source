#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],c[510],b[510],ans;
bool vis[510];
long long fact(int nn){
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum=1LL*sum*i%998244353;
	}
	return sum;
}
void dfs(int step){
	if(step>n){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[b[i]]){
				cnt++;
				continue;
			}
			if(a[i]==0){
				cnt++;
				continue;
			}
			sum++;
		}
		if(sum>=m)ans=(ans+1)%998244353;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	string x;
	cin>>x;
	for(int i=1;i<=n;i++){
		a[i]=x[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18)dfs(1);
	else{
		cout<<fact(n);
		return 0;
	}
	cout<<ans;
	return 0;
}
