#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nx;
	cin>>nx;
	int num=1;
	for(int i=2;i<=n*m;i++){
		int cnt;
		cin>>cnt;
		num+=(cnt>nx);
	}
	int ny=(num/(n*2));
	int ny1=(num%(n*2));
	int y=ny*2+(ny1>n)+1;
//	cout<<y;
	int x;
	if(ny1<=n){
		x=ny1;
	}
	else{
		x=ny1-n;
	}
	cout<<y<<' '<<x;
	return 0;
}