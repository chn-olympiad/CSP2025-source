#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,lans;
int dfs(int d,int sum){
	queue<int> q;
	q.push(a[d]);
	if(sum==k) return max(ans,lans);
	while(!q.empty()){
		int x=a[d];
		sum^=x;
		ans++;
		lans=ans;
		dfs(d+1,sum);
		sum^=x;
		q.pop();
		ans--;
	}
	return max(ans,lans);
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,0);
	return 0;
}
