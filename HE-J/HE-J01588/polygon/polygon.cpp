#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n,ans=0;
void f(int m,int j,int maxn,int ii,int anss){
	if(j==m){
		if(maxn*2<anss){
			ans++;
		}
		return;
	}
	for(int i=ii+1;i<=n-m+j+1;i++){
		f(m,j+1,max(maxn,a[i]),i,anss+a[i]);
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
		f(i,0,0,0,0);
	}
	cout<<ans%998244353;
}
