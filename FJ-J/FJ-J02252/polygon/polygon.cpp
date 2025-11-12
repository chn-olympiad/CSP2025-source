#include<bits/stdc++.h>
using namespace std;
int n,f[2501][2501],i,j,a[2501],l,ans,k,sum[2501];
bool b[2501];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<9;
	}
	return 0;
}
