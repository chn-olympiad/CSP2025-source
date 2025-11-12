#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105],n,m,num=1;
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[1]<a[i])
			num++;
	}
	int x=num/n+1;
	int y=(x%2)?(num%n):(n-num%n+1);
	cout<<x<<' '<<y;
	return 0;
}
