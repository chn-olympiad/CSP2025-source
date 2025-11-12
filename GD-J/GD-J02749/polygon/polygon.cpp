#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[1005];
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	if(a[3]*2<sum) cout<<1;
	else cout<<0;
	return 0;
}
