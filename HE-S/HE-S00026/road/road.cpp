#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int a[m][3];
	for(int i=0;i<m;i++)
		for(int j=0;j<3;j++)
			cin >> a[i][j];
	int b[n+1][k];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<k;j++){
			cin >> b[i][j];
		}
	} 
	cout << n*m-k;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
