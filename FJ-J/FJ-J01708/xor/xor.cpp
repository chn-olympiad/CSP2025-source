#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,k,ans=0;
void dfs(int s,int sum,int num){
	if(s>n-1){
		ans=max(ans,num);
		return ;
	}
	for(int i=s;i<=n;i++){
		sum=sum^a[i];
		if(sum==k){
			num++;
			dfs(i+1,0,num);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	
	return 0;
} 
