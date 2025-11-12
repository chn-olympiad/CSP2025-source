#include<bits/stdc++.h>
using namespace std;

int a[5003],b[5003];
int n;
long long ans;

void dfs(int cnt,int d,int h,int m){
	if(d==n){
		if(h>=3 and cnt>2*m){
			ans=(ans+1)%998244353;
		}
		return;
	}
	dfs(cnt,d+1,h,m);
	dfs(cnt+a[d],d+1,h+1,a[d]);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
