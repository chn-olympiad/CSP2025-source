#include<bits/stdc++.h>
using namespace std;
int n,a[5050],s[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	if(n<=3) {
		if(s[n]>a[n]*2) cout<<1;
		else cout<<0;
	}
	return 0;
}