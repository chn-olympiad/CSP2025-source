#include <bits/stdc++.h>
using namespace std;
int n,cnt,ans;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n=3) cout<<1;
	if(n=4){
	for(int i=1;i<=n;i++){
		if(a[i]+a[i+1]>a[i+2])
		cnt++;
		if(a[i]+a[i+1]>a[i+3])
		cnt++;
		if(a[i]+a[i+2]>a[i+3])
		cnt++;
	}
	cnt+=(n*n-5*n+6)/2;
	cout<<cnt;
	}
	return  0;
}
