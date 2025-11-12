#include<bits/stdc++.h>
using namespace std;
long long a[1001][1001];
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
			cin>>a[i][j];
	cout<<n<<" "<<m;
	return 0;
}
