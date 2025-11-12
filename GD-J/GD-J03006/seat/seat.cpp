#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,r,p=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(a<b)p++;
	}
	c=(p+n-1)/n;r=(p-1)%n+1;
	if(c%2==0)r=n-r+1;
	cout<<c<<' '<<r;
	return 0;
}
