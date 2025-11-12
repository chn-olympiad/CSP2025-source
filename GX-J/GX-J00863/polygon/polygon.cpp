#include <bits/stdc++.h>
using namespace std;
int a[500005],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<a[n]+a[n-1];
return 0;
}
