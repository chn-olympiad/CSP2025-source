#include<bits/stdc++.h>
using namespace std;

long long n,arr[5005];
long long ans;

void dfs(int x,int he,int step){//wo zai "bu yao xiao tiao zhan"zhong huo de le 0s de hao cheng ji ni ye lai shishi ba!
	if(x == n) return;
	if(step>2&&he-arr[x]>arr[x]) ans++;
	for(int i=x+1;i<n;i++){
		dfs(i,he+arr[i],step+1);
	}	
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		dfs(i,arr[i],1);
	}
	cout<<ans;
	
	return 0;
}
