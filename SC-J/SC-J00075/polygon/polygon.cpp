#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5010];
int val[5010];
int cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		
	}
	if(a[n]==1){
		cnt=(n-1)*(n-2)/2;
		cnt%=998244353;
	}
	cout<<cnt;
	return 0;
} 