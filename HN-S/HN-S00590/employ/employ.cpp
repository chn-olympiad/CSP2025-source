#include<bits/stdc++.h>
using namespace std;
int n,m,c,a[505];
long long sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
sum=1;
	cin>>n>>m;
	cin>>c;
	for(int j=0;j<n;j++){
		cin>>a[j];
		if(a[j]>1)
		sum*=a[j];
	}
	for(int j=m;j>=n;j--){
		sum*=j;
	}
		for(int j=m-n;j>1;j--){
		sum/=j;
	}
	cout<<sum%998244353;
	return 0;
}
