#include <bits/stdc++.h>
using namespace std;
int n,a[6000],sum,answer;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];sum+=a[i];
	}
	sort(a+1,a+n+1);
	cout<<n-2;
	return 0;
}
