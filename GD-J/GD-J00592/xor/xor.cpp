#include<bits/stdc++.h>
using namespace std;
int arr[1010],ans; int n,k;
void dfs(int cnt,int x){
	if(x>n){
		ans=max(ans,cnt);
		return;
	}
	if(x<=n) dfs(cnt,x+1);
	int sum=0;
	for(int i=x;i<=n;i++){
		sum^=arr[i];
		if(sum==k){
			//cout<<x<<i<<'\n';
			dfs(cnt+1,i+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(0,1);
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
