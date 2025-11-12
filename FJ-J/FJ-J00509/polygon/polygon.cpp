#include<bits/stdc++.h>
using namespace std;
long long a[50001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out ","w",stdout);
	int n=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	sum=sum-n-1;
	int s=0;
	s=sum%998244353;
	cout<<s;
	return 0;
}
