#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],cnt=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i]+1!=a[i+1])cnt=0;
	}
	if(cnt==1)cout<<n*2-1;
	else cout<<"0";
	return 0;
}
