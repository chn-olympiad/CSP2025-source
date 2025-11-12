#include<bits/stdc++.h>
using namespace std;
int n,m;
char x[505];
int a[505];
int ans;
int used[505],ans1[505];
void dfs(int i){
	if(i>n){
		int s=0,fq=0;
		for(int j=1;j<=n;j++){
			if(x[j]=='0'||fq>=a[ans1[j]])fq++;
			else s++;
		}
		if(s>=m)ans++;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(used[j]==0){
			used[j]=1;
			ans1[i]=j;
			dfs(i+1);
			used[j]=0;
			ans1[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int s0=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(x[i]=='0')s0++;
	}
	
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=18){
		dfs(1);
		cout<<ans;
		return 0;	
	}
	if(s0>n-m){
		cout<<0;
		return 0;
	}
	if(m==n){
		if(s0>=1){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++)ans*=i;
		cout<<ans;
		return 0;
	}
	return 0;
}
