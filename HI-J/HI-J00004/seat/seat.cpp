#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int ks[1000];
int emp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sl = n*m;
	for(int i=1;i<=sl;i++) cin>>ks[i];
	int R=ks[1];
	sort(ks+1,ks+sl+1,emp);
	int hao=1;
	int x=1,y=1;
	while(hao <= sl){
		while(x<=n){
			a[x][y] = ks[hao];
			x++;
			hao++;
		}
		x--;
		y++;
		while(x>=1){
			a[x][y] = ks[hao];
			x--;
			hao++;
		}
		x++;
		y++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j] == R){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	
	return 0;
}
