#include <bits/stdc++.h>
using namespace std;
const int MaxN=5010;
int a[MaxN];
int nums[MaxN];
bool flag[MaxN];
int n;
int ans=0;
int j1=0;
bool compare(int a,int b){
	return a>b;
}
void push(int mu){
	for(int i=0;i<j1;i++){
		if(nums[i]==mu){
			nums[i]=0;
			break;
		}
	}
	sort(nums,nums+j1,compare);
}
bool check(int m){
	sort(nums,nums+m+1,compare);
	int n1=nums[0];
	int ans=0;
	for(int i=0;i<j1;i++){
		ans+=nums[i];
	}
	if(ans>n1*2) return true;
	return false;
} 
void dfs(int m){
	if(j1>2){
		if(check(j1)){
			ans++;
		}
	}
	if(m==n){
		return;
	}
	for(int i=m;i<n;i++){
		if(flag[i]) continue;
		nums[j1]=a[i];
		j1++;
		flag[i]=true;
		dfs(i);
		flag[i]=false;
		push(a[i]);
		j1--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans%998244353<<endl;
	return 0;
	
}
