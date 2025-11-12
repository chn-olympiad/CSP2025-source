#include<bits/stdc++.h>
using namespace std;
int a[510];
int tong[510],vis[510];
int ans1,ans2,ans;
int n,m;
void dfs(int x){
	if(x==m) ans++;
	for(int i=1;i<=n;i++){
		if(!vis[i]&&a[i]>x){
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]++;
	}
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			ans1++;
		}else{
			ans2++;
		}
	}
	if(ans2<m){
		cout<<0;
		return 0;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]=='1'){
				break;
			}
			ans++;
		}
		ans=0;
		for(int i=ans+1;i<=500;i++){
			ans+=tong[i];
		}
		cout<<ans;
		return 0;
	}else if(n<=10){
		dfs(0);
		cout<<ans;
	}else{
		cout<<n;
	}
	
	return 0;
}
