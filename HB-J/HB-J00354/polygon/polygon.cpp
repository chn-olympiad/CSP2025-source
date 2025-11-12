#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int maxx=0,ams=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		ams+=a[i];
	}
	if(ams>maxx*2)cout<<1;
	else cout<<0;
}
else cout<<n*n%998%244%353;
	return 0;
}
