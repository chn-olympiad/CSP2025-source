#include<bits/stdc++.h>
using namespace std;
int n;
long long int a[5010];
long long int sum,s;
void dfs(int x,int y){
	if(y==0){
		if(x*2<s){
			sum++;
		}
		return ;
	}
	for(int i=x+1;i<=n;i++){
		s+=a[i];
		dfs(i,y-1);
		s-=a[i];
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n-i;j++){
			s=a[i];
			dfs(i,j);
		}
	}
	cout<<sum%998244353;
	return 0;
}
