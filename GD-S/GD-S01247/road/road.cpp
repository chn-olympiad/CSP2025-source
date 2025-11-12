#include <bits/stdc++.h>
using namespace std;

int n,m,k,a[100005][100005],b[100005][100005],sum=0;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			cin >> a[i][j];
		}
	}
	for (int i=1;i<=k;i++){
		for (int j=1;j<=n+1;j++){
			cin >> b[i][j];
		}
	}
	
	if (k==0){
		for (int i=1;i<=n;i++){
			sum+=a[i][3];
		}
		cout << sum;
	}
	return 0;
}
