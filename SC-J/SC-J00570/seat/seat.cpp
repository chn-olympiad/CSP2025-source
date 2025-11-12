#include<bits/stdc++.h>
using namespace std;
int a[230],b[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+m*n+1);
	int k=m*n;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				b[i][j]=a[k--];
				if(b[i][j]==t)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=m;j++){
				b[i][j]=a[k--];
				if(b[i][j]==t)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
}