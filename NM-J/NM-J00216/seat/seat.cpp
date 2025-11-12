#include <bits/stdc++.h>
using namespace std;

int n,m,c,r,a[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>c>>r;
	int a=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if (a<(a+1)){
			r=j+1;
			c=1;
		}
		else r=1;
	break;
		}
		if (a<(a+1)){
			c=i+1;
			r=1;
		}
		else c=1;
	break;
	}
	cout<<c<<"  "<<r;
	return 0;
}

