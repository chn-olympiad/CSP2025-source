#include<bits/stdc++.h>
using namespace std;
int a[5005],t[5005];
int n,ans,cnt;
void dfs(int x,int sum){
	if(x>n){
		if(cnt<3){
			return;
		}
		for(int i=1;i<=cnt;i++){
			if(t[i]*2>=sum){
				return;
			}
		}
		ans=(ans+1)%998244353;
		return;
	}
	for(int i=0;i<=1;i++){
		if(i){
			t[++cnt]=a[x];
			dfs(x+1,sum+a[x]);
			cnt--;
		}else{
			dfs(x+1,sum);
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
