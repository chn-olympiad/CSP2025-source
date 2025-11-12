#include<bits/stdc++.h>
using namespace std;
int a[1005];
int ans[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1);
	int now=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans[j][i]=a[now--];
			}
		}
		else {
			for(int j=n;j>=1;j--){
				ans[j][i]=a[now--];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==num){
				cout<<j<<' '<<i<<'\n';
				return 0;
			}
		}
	}
}
