#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
     return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],b[13][13];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int s=a[1];
	sort(a+1,a+n+1,cmp);
	for(int k=1;k<=m;k++){
		for(int t=1;t<=n;t++){
		if(k%2!=0) {
			b[k][n]=a[k*n];
			b[k][n+1]=a[k*n+1];
			b[k][n+2]=a[k*n+2];
			b[k][n+3]=a[k*n+3];
			}
		else {b[k][1]=a[k*n];
			b[k][n-1]=a[k*n-1];
			b[k][n-2]=a[k*n-2];
			b[k][n-3]=a[k*n-3];
		}
	}
	}
	for(int i=1;i<=n;i++)
{
	for(int	j=1;j<=m;j++){
		if(b[j][i]==s) cout<<j<<" "<<i;
	}
}	
	return 0;
}
