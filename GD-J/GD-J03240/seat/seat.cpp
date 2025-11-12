#include<bits/stdc++.h>
using namespace std;
int se[15][15],n,m,a[105],b;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(se,0,sizeof(se));
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i%2==0)se[i][j]=a[m*i+j];
			else se[i][m-j-1]=a[m*i+j];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(se[i][j]==b)cout<<i+1<<' '<<j+1;
		}
	}
	return 0;
}
