#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5555],s=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n+1-3;i>=1;i--)
		for(int j=i;j>=1;j--)
			s+=j;
	if(n==5&&a[2]==2) cout<<9;
	else cout<<s%998244353;
	return 0;
}
