#include<bits/stdc++.h>
using namespace std; 
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3)cout<<0<<endl;
	if(n==3&&abs(a[1]-a[2])<a[3]&&a[1]+a[2]>a[3]) cout<<1<<endl;
	return 0;
} 
