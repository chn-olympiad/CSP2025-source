#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
bool v[5005];
void dfs(int k,int m,int z){
	if(k==m+1){
		long long maxx=0,sum=0;
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(v[i]) maxx=max(maxx,a[i]);
		}
		for(int i=1;i<=n;i++){
			if(v[i]){
				if(maxx==a[i]&&flag) flag=false;
				else sum=sum+a[i];
			}
		}
		if(sum>maxx) ans++;
	}
	for(int i=z+1;i<=n;i++){
		v[i]=1;
		dfs(k+1,m,i);
		v[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,0);
	}
	cout<<ans;
	return 0;
}
