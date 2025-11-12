#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long int n,result=0;
long long int a[N];
void dfs(long long int sum,long long int m,long long int id,long long int use){
	if(id>n){
		return;
	}
	sum=sum+a[id];
	m=max(m,a[id]);
	if(id>=1){
		use++;
	}
	if(sum>2*m&&use>=3){
		result++;
	}
	for(int i=id+1;i<=n;i++){
		dfs(sum,m,i,use);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<result%998244353;
	return 0;
}
