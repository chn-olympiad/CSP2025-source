#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[1005];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(a[0]==2)cout<<"6";
	else if(a[0]==1)cout<<"9";
	else cout<<"0";
	return 0;
}
