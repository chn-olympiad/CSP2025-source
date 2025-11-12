#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx;
long long anss;
void f(int i,int ans,int m){
	if(i==n+1){
		if(ans>2*m){
			anss++;
		}
		return ;
	}
	if(ans>2*maxx){
		long long c=1;
		for(int j=i;j<n+1;j++){
			c*=2;
		}
		anss+=c;
		return ;
	}
	f(i+1,ans+a[i],max(m,a[i]));
	f(i+1,ans,m);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	f(1,0,0);
	cout<<anss;
	return 0;
}
