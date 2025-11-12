#include<bits/stdc++.h>
using namespace std;
int n,a[5005],z=0,p=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1);
	z+=a[1]+a[2]+a[3];
	if(z>a[3]*2) p++;
	cout<<p;
	return 0;
}
