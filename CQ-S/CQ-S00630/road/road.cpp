#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a,b,c;
int x,y;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		cin >> a >> b >> c;
		x+=c;
		y=max(y,c);
	}
	x-=c;
	for (int i=1;i<=k;i++){
		c=0;
		cin >> a;
		c+=a;
		for (int j=1;j<=n;j++){
			cin >> b;
			c+=b;
		}
		x=min(x,c);
	}
	cout << x;
	return 0;
}


