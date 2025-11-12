#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
