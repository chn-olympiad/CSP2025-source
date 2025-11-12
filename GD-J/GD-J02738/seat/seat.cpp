#include<bits/stdc++.h>
using namespace std;
int n,m,ans,x,y,z;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]) ans++;
	}
	x=ans/n;
	y=ans%n;
	if(y) x++;
	else y=n;
	if(x%2) cout<<x<<" "<<y;
	else cout<<x<<" "<<n-y+1;
	return 0;
} 
