#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int n,m,k;
long long rdct[100][100];
struct rd{
	int cne,cwo;
	int cst;
}a[100010];
struct ctsd{

	int selfct;
}b[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].cne>>a[i].cwo>>a[i].cst;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].selfct;
		for(int j=1;j<=m;j++){
			cin>>rdct[i][j];
		}
	}
	
	return 0;
} 
