#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b[101][101];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ls=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,k=0;i<=n;i++,k++){
		if(i%2==1) for(int j=1;j<=m;j++) b[j][i]=a[k*n+j];
		else for(int j=m,x=1;j>=1;j--,x++) b[j][i]=a[k*n+x];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==ls){
				cout<<j<<" "<<i;
				return 0;
			}
	return 0;
}
