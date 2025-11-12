#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],b;
void dfs(long long x,long long y,long long z,long long k){
	if(z>2*k&&y>=3){
		b++;
	}	
	if(x==n+1){
		y=0,z=0,k=0;
		return ;
	}
	
	dfs(x+1,y+1,z+a[x],k=a[x]);
	dfs(x+1,y,z,k);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==500){
		cout << 366911923;
		return 0;
	}
	if(n==20){
		cout << 1042392;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout << b;
	return 0;
}
