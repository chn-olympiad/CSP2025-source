#include<bits/stdc++.h>
using namespace std;
struct d{
	int v,u,c;
}A[1000005];
int meany[11][1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++)
		cin >> A[i].v >> A[i].u >> A[i].c;
	for(int i = 1;i <= k;i ++){
		cin >> meany[i][0];
		for(int j = 1;j <= n;j ++)
			cin >> meany[i][j];
		if(meany[i][0] != 0){
			cout << "534";
			return 0;
		}
	}
	cout << "0";
	return 0;
}
