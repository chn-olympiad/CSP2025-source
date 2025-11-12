#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n;
int g[N];
int ls[N];
bool flag[N];
int ans;
void dfs(int r){
	int tt=1;
	if(r>=3){
		int cnt=0,maxl=0;
		for(int i=1;i<=r;i++){
			cnt+=ls[i];
			maxl=max(maxl,ls[i]);
		}
		if(cnt>2*maxl)ans++;
	}
	for(int i=1;i<n;i++){
		if(flag[i])continue;
		ls[r]=g[i];
		flag[i]=true;
		dfs(r++);
		flag[i]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	int cnt=0;
	int maxl=0;
	for(int i=1;i<=n;i++){
		cin>>g[i];
		cnt+=g[i];
		maxl=max(maxl,g[i]);
	}
	if(n==3){
		if(cnt>2*maxl){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

