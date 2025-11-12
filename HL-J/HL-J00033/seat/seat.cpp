#include <bits/stdc++.h>
using namespace std;
const int N=15;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[N][N],c[N*N],s[N*N];
	int n,m,smalls;
	cin >> n >> m;
	if(n==1&&m==1){
		cout << "1 1";
		return 0;
	}
	for(int i=1;i<=n*m;i++)cin >> c[i];
	smalls=c[1];
	if(c[1]==100){
		cout <<"1 1";
		return 0;
	}
	cout << smalls/m<< " " << smalls/n+1;
	return 0;
}