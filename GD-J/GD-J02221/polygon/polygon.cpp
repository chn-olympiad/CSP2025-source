#include<bits/stdc++.h>
using namespace std;
const int N=5e3+53,M=998244353;
int n,a[N],ans,mm;
void dfs(int x,int h){
	if(x>n)return;
	if(h>a[x]){
		ans++;
		if(ans>=M)ans-=M;
	}
	dfs(x+1,h+a[x]);
	dfs(x+1,h);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mm=max(mm,a[i]);
	}
	if(mm==1){
		cout<<(1<<n)-n*(n-1)/2-n-1;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ans;
	return 0;
}
