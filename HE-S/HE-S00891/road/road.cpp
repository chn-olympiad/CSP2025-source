#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int ua[m],ub[m],w[m];
	int a[10][100];
	int b[10];
	int p=0;
	int ans=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<100;j++){
			a[i][j]=0;
		}b[i]=0;
	}
	for(int i=0;i<m;i++){
		cin >>ua[i];

		cin >ub[i];
		cin >>w[i];
		ans+=w[i];
	}cout << ans;
	return 0;
}
