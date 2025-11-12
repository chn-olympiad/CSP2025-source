#include<bits/stdc++.h>
using namespace std;
int n,a[5010],d[5010],vis[5010],ans;
bool check(int id){
	int mx=0,cnt=0;
	for(int i=1;i<=id;i++){
		cnt+=a[d[i]];
		mx=max(mx,a[d[i]]);
	}
	if(cnt>2*mx&&id>=3){
		return true;
	}
	else{
		return false;
	}
}
void dfs(int x,int id){
	if(id==n+1){
		return;
	}
	if(check(id)){
		ans++;
		ans%=998244353;
	}
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			d[id+1]=i;
			dfs(i,id+1);
			vis[i]=0;
			d[id+1]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

