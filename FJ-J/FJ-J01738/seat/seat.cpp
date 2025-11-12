#include <bits/stdc++.h>
using namespace std;
int a[15][15],n,m,b[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> b[i];
	}
	int xiaor=b[1],l=n*m;
	sort(b+1,b+n*m+1);
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				if (b[l]==xiaor) {
					cout << i << " " << j;
					return 0;
				}
				l--;
			} 
		}
		if (i%2==0){
			for (int j=n;j>=1;j--){
				if (b[l]==xiaor) {
					cout << i << " " << j;
					return 0;
				}
				l--;
			} 
		}
	}
	return 0;
}

