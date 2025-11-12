#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100001],as[100001],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		as[i]=as[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	cout<<sum;
	return 0;
}

