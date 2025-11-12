#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
int max1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	if(n==3&&a[1]+a[2]+a[3]>max1*2) cout<<1;
	return 0;
}