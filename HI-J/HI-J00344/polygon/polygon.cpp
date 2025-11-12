#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0;
	cin>>n;
	int a[n+5];
	for(int i=0;i<n;i++) cin>>a[i];
	if(a[0]+a[1]>max(a[0]*2,a[1]*2)) s++;
	if(a[2]+a[1]>max(a[2]*2,a[1]*2)) s++;
	if(a[0]+a[2]>max(a[0]*2,a[2]*2)) s++;
	sort(a,a+n);
	if(a[0]+a[2]+a[1]>a[2]*2) s++;
	cout<<s;
	return 0;
}
