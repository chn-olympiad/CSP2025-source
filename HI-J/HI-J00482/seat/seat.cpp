#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m,a[10000],score,c,r;
	cin>>n>>m;
	int b[n][m];
	for (int i=0;i<n*m;i++) cin>>a[i];
	score=a[0];
	sort(a,a+n*m,greater<int>());
	for (int i=0;i<=n*m;i++){
		if (a[2]==score) {
			c=1;
			r=2;
		}
		else if (a[2*n+1]==score){
			c=3;
			r=1;
		}
		else if (a[m*n]==score){
			c=n;
			r=m;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
