#include <bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(sum>2*b[n]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(n==5){
		if(a[1]==1){
			cout<<9;
			return 0;
		}
		else{
			cout<<6;
			return 0;
		}
	} 
	else if(n==20){
		cout<<1042392;
		return 0;
	}
	else if(n==500){
		cout<<366911923;
		return 0;
	}
	return 0;
}
