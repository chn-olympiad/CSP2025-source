#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in.txt","r",stdin);
	freopen("polygon.out.txt","w",stdout);
	int n;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3) {
		cout<<0;
		return 0;
	}
	int mx=max(a[2],a[3]);
	int m=max(a[1],mx);
	if(a[1]+a[2]+a[3] > m*2) cout<<1;
	else cout<<0;
	return 0;	
}
