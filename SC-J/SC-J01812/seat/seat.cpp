#include <iostream>
#include <algorithm>
using namespace std;
const int N=13;
int a[N*N];
int b[N][N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>a[i];
	}
	int lr=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int i=1,j=0,cnt=0;
	while(j<=m) {
		j++;
		if(i<1) i=1;
		while(!b[i][j] && i<=n) {
			b[i][j]=a[++cnt];
			i++;
		}
		j++;
		if(j>m) break;
		if(i>n) i=n;
		while(!b[i][j] && i>=1) {
			b[i][j]=a[++cnt];
			i--;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(b[i][j]==lr) {
				cout<<j<<' '<<i;
				break;
			}
		} 
	}
	return 0;
}