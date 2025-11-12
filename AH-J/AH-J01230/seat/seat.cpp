#include<bits/stdc++.h>
using namespace std;
int n,m,xz;
int a[10005],k;
int st[105][105];
;int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	xz=a[1];k=n*m+1;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				k--;
				st[j][i]=a[k];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				k--;
				st[j][i]=a[k];
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(xz==st[i][j]){
				cout<<j<<' '<<i;
				return 0;
			}
	return 0;
}
//94 95 96 97 98 99 100 93 92
