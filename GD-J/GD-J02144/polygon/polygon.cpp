#include<bits/stdc++.h>
using namespace std;
long long a[1000];
bool b[1000];
long long sum = 0;
long long n;
void dfs(long long  x,long long y,long long z,long long l){
	if(x>y*2&&z>=3){
	sum=(sum+1)%998244353;
	}
	for(int i = l;i<=n;i++){
		if(b[i])continue;
		long long tx = x+a[i];
		long long ty = max(y,a[i]);
		long long tz = z+1;
		b[i] = 1;
		dfs(tx,ty,tz,i);
		b[i] = 0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon,out","w",stdout);
	cin>>n;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<sum;
	return 0;
} 
