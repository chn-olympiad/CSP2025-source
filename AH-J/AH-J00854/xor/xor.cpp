#include<bits/stdc++.h>
using namespace std;
long long arr[200010],n,k;
int dfs(int start){
	int max_=0;
	for(int j=start;j<n;j++){
		int amount=arr[j];
		for(int i=j+1;i<=n;i++){
			if(amount==k)max_=max(max_,dfs(i)+1);
			else amount^=arr[i];
		}
	}
	return max_;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<dfs(0);
	return 0;
}
