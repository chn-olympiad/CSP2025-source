#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=n*m;
	int a[z];
	cin>>a[z];
	sort(a[0],a[z-1]);
	cout<<a[z]<<'\n';
	return 0;
}
