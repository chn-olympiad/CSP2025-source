#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	int n,a[5100],b=0;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=3){
		int c=a[0]+a[1]+a[2],d=max(a[0],max(a[1],a[2]));
		if(c>2*d)cout<<1;
		else cout<<0;
	}
	return 0;
}