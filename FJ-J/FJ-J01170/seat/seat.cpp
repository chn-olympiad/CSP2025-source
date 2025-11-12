#include <bits/stdc++.h>
using namespace std;
int a[105],r,n,m,k=1,fx=2,ans[15][15],co=1,cou=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		r=a[1];
	}
	sort (a+1,a+n*m+1,cmp);
	ans[1][1]=a[1];
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (fx==0)co--;
			else if (fx==1)cou++;
			else co++;
			k++;
			ans[co][cou]=a[k];
			
			if (co==n){
				if (cou%2==0)fx=0;
				else fx=1;
			}
			else if (co==1){
				if (cou%2==0)fx=1;
				else fx=2;
			}
			ans[1][1]=a[1];
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (ans[i][j]==r){
				cout<<j<<" "<<i;
				
				return 0;
			}
		}
	}
	return 0;
}
