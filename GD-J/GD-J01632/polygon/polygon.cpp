#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n , A[5010];
long long dfs(int cnt,int ind){
	if(ind>=n)return 1;
	long long ans=0;
	for(int i=ind;i < n;i++){
		if(cnt+A[i]>A[i]*2)ans+=dfs(cnt+A[i],ind+1);
		ans%=mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>> n;
	for(int i=0;i < n;i++){
		cin>> A[i];
	}
	sort(A,A+n);
	cout<< dfs(0,0);
	return 0;
}
