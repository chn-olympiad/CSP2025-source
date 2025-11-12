#include<bits/stdc++.h>
using namespace std;
int a[122],n,m,r,y,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}r=n*m;
	for(int i=2;i<=n*m;i++){
		if(a[i]<a[1]) r--;
	}y=r%n;
	if(y==0) y=n,s=r/n;
	else s=r/n+1;
	if(s%2==0) cout<<s<<' '<<n-y+1;
	else cout<<s<<' '<<y;
	return 0;
}
