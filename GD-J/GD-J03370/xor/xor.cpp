#include<bits/stdc++.h>
using namespace std;
int n,k;
int cnt;
int t[510000];
int vis[510000];
void dfs(int id){
	if(id>n){
		return;
	}
	for(int i=id;i<=n;i++){
		int x=0;
		for(int j=i+1;j<=n;j++){
			if(vis[i]==0&&vis[j]==0){
//				cout<<t[i]<<t[j];
				if(j=i+1){
					x+=t[i]^t[j];
				}else{
					x+=x^t[j];
				}
//				cout<<x<<" ";
				if(x==k){
					vis[i]=1;
					vis[j]=1;
					cnt++;
					dfs(i+1);
				}
			}else{
				break;
			}
		} 
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		if(t[i]==k&&vis[i]==0){
			cnt++;
			vis[i]=1;
		}
	}
	dfs(1);
	cout<<cnt;
	return 0;
}
