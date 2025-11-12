#include<bits/stdc++.h>
using namespace std;
const int N=1e7*3+101;
long long n,a[N],ans;
void dfs(long long s,long long z,long long x,long long mx){
	if(mx*2<z&&s>=3)ans++;
	for(int i=x+1;i<=n;i++){
		dfs(s+1,z+a[i],i,mx);
	}
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		dfs(1,a[i],i,a[i]);
	}
	cout<<ans;
	return 0;
}
