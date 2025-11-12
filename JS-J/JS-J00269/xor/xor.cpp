#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k,a[500005],ans;
bool spec=1;
void dfs(int dep,int val,int res){
	if(dep>=n){
		if(val==k)ans=max(ans,res+1);
		else ans=max(ans,res);
		return;
	}
	if(val==k){
		for(int i=dep+1;i<=n;i++){
			dfs(i,a[i],res+1);
		}
	}
	else{
		for(int i=dep+1;i<=n;i++){
			dfs(i,val^a[i],res);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	if(k>1)spec=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)spec=0;
	}
	if(spec){
		if(k==0){
			int i=1;
			while(i<=n){
				if(a[i]==0){
					ans++;
					i++;
				}
				else if(a[i]==1 && a[i+1]==1){
					ans++;
					i+=2;
				}
				else i++;
			}
		}
		else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,a[i],0);
	}
	cout<<ans;
	return 0;
}
