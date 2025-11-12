#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
int a[5005];
int b[5005];
void dfs(int i,int m){
	if(i>n-2&&m<1) return;
	if(i>n-1&&m<2) return;
	if(i>n){
		if(m<3){
			return;
		}
		int num=0,maxx=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				num+=a[i];
				maxx=max(maxx,a[i]);
			}
		}
		if(num>maxx*2){
			ans++;
		}
		return;
	}
	b[i]=1;
	dfs(i+1,m+1);
	b[i]=0;
	dfs(i+1,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ans%998244353;
	return 0;
} 
