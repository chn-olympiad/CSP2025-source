#include <bits/stdc++.h>
using namespace std;
int n,m;
long long s,cnt=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n*m-1;i++){
		int a=0;
		cin>>a;
		if (a>s) cnt++;
	}
	c=(cnt+n-1)/n;
	if (c%2==1){
		r=cnt-n*(c-1);
	}
	else r=c*n-cnt+1;
	cout<<c<<" "<<r;
	return 0;
}
