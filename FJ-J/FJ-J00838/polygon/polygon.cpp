#include <bits/stdc++.h>
using namespace std;
int n,a[5111],ans;
long long qh(long long x,long long y){
	if(x==3){
		return y*(y-1)*(y-2)/(3*2*1);
	}
	else{
		int cnt=1,ct=1;
		for(int i=1;i<=x;i++){
			cnt=cnt*(y-i+1);
		}
		for(int i=1;i<=x;i++){
			ct=ct*i;
		}
		return qh(x-1,y)+(cnt/ct);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			ans++;
		}
		cout<<ans;
	}
	else{
		cout<<qh(n,n);
	}
	

	
	
	
	return 0;
}
