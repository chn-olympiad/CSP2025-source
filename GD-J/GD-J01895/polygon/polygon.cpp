#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long num,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	cout<<n/2;
	return 0;
}
