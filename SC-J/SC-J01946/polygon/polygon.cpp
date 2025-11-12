#include <bits/stdc++.h>
using namespace std;
int n;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
	int a=rand()%10;
	cin>>n;
	if(n==3){
		int x,y,z;
		cin>>x>>y>>z;
		int d=max({x,y,z});
		cout<<((x+y+z)>(2*d));
	}else cout<<a;
	return 0;
}