#include<bits/stdc++.h> 
using namespace std;
int jc(int n){
	int s=1;
	for(int i=1;i<=n;i++){
		s*=n;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=3;i<=n;i++){
	    sum+=jc(n)/(jc(i)*jc(n-i));
	}
	sum%=998244353;
	cout<<sum;
	return 0;
}
