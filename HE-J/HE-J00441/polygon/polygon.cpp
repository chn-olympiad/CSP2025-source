#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a[100001],sum,m,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		x=max(a[i],a[i+1]);
		if(sum>2*x){m++;}
	}
	cout<<m;
	return 0;}

