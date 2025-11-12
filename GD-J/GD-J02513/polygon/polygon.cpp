#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int max1=0;
long long sum=0;
long long ans;
long long C(int n,int n1){
	if(n1==1){
		return n;
	}
	else if(n1==n){
		return 1;
	}
	else{
		return C(n-1,n1-1)+C(n-1,n1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int n1=n;
	while(n1--){
		cin>>a[n1];
		sum+=a[n1];
		max1=max(max1,a[n1]);
	}
	if(n!=3){
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
		}
		cout<<ans;
		return 0;
	}
	if(max1*2<sum){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
