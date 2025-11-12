#include<bits/stdc++.h>
using namespace std;
int n,a[5123],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	if(sum>a[n]*2)cout<<1;
	else cout<<0;
	return 0;
} 
