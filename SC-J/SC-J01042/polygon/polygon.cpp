#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N],b,ans;int n;
void dfs(int i,int m){
	if(i==n){
		if(b>2*m){
			ans++;
		}return;
	}
	dfs(i+1,m);
	b+=a[i];
	dfs(i+1,max(a[i],m));
	b-=a[i];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans%998244353;
	return 0;
}