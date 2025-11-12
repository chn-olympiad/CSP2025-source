#include <bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],cnt=0,mxx=0,summ=0;
void dfs(int mx,int g,int sum,int i){
	if(i==n)return;
	if(g>=3 && mx*2<sum){
		cnt++;
		cnt%=998244353;
	}
	for(int k=i+1;k<=n;k++){
		dfs(max(mx,a[k]),g+1,sum+a[k],k);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxx=max(mxx,a[i]);
		summ+=a[i];
	}
	if(n==3){
		if(summ>mxx*2)cout<<1;
		else cout<<0;
	}else{
		dfs(0,0,0,0);
		cout<<cnt;
	}
	return 0;
}