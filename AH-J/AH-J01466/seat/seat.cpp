#include <bits/stdc++.h>
using namespace std;
int n,m,x,t,l,h,pos;
int a[110],g[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	l=1;
	h=1;
	sort(a+1,a+n*m+1,greater<int>());
	while(t!=n*m){
		if(l%2==1){
			for(int i=1;i<=n;i++){
				g[i][l]=a[++pos];
				t++;
			}
			l++;
		}else{
			for(int i=n;i>=1;i--){
				g[i][l]=a[++pos];
				t++;
			}
			l++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==x){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
