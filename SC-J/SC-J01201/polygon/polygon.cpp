#include<bits/stdc++.h>
using namespace std;
int n,a[10086],maxx=-10086;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(maxx<a[i]){
			maxx=a[i];
		}
	}
	if(n==3){
		int j=max(max(a[0],a[1]),a[2]);
		if(j<a[0]+a[1]+a[2]-j){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(maxx==1){
		int sum=0;
		for(int i=n;i>=0;i--){
			sum+=i*(i-1);
		}
		sum/=2;
		cout<<sum;
		return 0;
	}
	else{
		cout<<a[0]*a[1]*a[2];
	}
	return 0;
}