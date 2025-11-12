#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long sum,z;
void dfs(int k,int t,int s){
	z++;
	if(z<1000000000){
		for(int i=t;i<=n;i++){
			if(k>=3&&s>a[i]) sum++;
			dfs(k+1,i+1,s+a[i]);
		}
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,1,0);
	cout<<sum%998244353;


	return 0;
}
