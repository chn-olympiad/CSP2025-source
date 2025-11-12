//GZ-S00381 贵阳市第三中学 胡景涵 
#include<bits/stdc++.h>
using namespace std;

int n,m,a[505],f[505],vis[505];long long ans;
deque<int> q;
bool check(){
	int Lost=0;int cnt=0;
	for(int i=0;i<q.size();i++){
		int n_ow=q[i];
		if(Lost>=f[n_ow]){
			Lost++;
			continue;
		}
		if(a[i+1]) cnt++;
		else Lost++;
		if(Lost>n-m) return 0;
	}
	if(cnt>=m) return 1;
	return 0;
}

void dfs(int c){
	if(c==n+1){
		if(check()) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		q.push_back(i);
		dfs(c+1);
		vis[i]=0;
		q.pop_back();
	}
	return ;
}

int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool ifa=1;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='0'){ifa=0;}else a[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>f[i];
		
	}
	//cout<<1;
	if(ifa){
		long long anc=1;
		int k=0;
		for(int i=1;i<=n;i++){
			if(f[i]>0){
				k++;
				anc*=k;
				anc%=998244353;	
			}
		}
		cout<<anc;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
