#include<bits/stdc++.h>
using namespace std;
#define M 998244353
int n,a[10001],s=0;
void dfs(int la,int sum,int mx,int k){
	if(k>3){
		if(sum>mx*2)
			s=(s+1)%M;
	}
	if(k==n+1)
		return;
	for(int i=la+1;i<=n;i++)
		dfs(i,sum+a[i],max(mx,a[i]),k+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		dfs(i,a[i],a[i],2);
	cout<<s;
}
