#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,f;
void dfs(int u,int m,int num,int k){
	if(k>=3&&2*m<num)ans++;
	for(int i=u+1;i<=n;i++){
		dfs(i,a[i],num+a[i],++k);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]==1)f++;
	}
	int r=1;	
	if(f==n){
		while(f--){
			r*=2;
			r%=998244353;
		}
		cout<<r-1-n-(n*n-n)/2;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(i,a[i],a[i],1);
	}
	cout<<ans;
	return 0;
}
