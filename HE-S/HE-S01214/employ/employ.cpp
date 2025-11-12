#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int a[5000];
int vis[5000];
int b[5000];
string s;
void dfs(int cnt){
	if(cnt==n+1){
		int x=0,top=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(b[i]<x){
				x++;
				continue;
			}
			else if(s[top]=='0'){
				x++;
				top++;
			}
			else if(s[top]=='1'){
				sum++;
				top++;
			}
		}
		if(m<=sum){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[i]=a[i];
			cout<<"b[i]:"<<b[i];
			dfs(cnt+1);
			cout<<"\n";
			vis[i]=0;
		}
	}
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
