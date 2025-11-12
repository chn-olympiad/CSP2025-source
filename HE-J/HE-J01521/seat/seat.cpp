#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n][m];
	int b[105] = {};
	int c[105],t=1,maxn=0;
	for (int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int cnt=0;
	for (int y=1;y<=n*m;y++){
		if (b[y]>b[0])
			cnt++;
	}
	cout<<(cnt+1)%n<<cnt/n;
	return 0;
}
