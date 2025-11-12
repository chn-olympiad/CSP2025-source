#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int a[N],n,sum,maxnum;
void dfs(int num,int he){
	if (num == 0){
		return ;
	}
	if (he>2*maxnum){
		sum++;
	}
	dfs(num-1,he+a[num-1]);
	if (num-1 > 1){
		dfs(num-1,he);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (a[n] == 1){
		cout<<pow(2,n)-1-n-n*(n-1)/2;
		return 0;
	}
	for (int i=n;i>=3;i--){
		maxnum = a[i];
		dfs(i,a[i]);
	}
	cout<<sum-1;
	return 0;
}
