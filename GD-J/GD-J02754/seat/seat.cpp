//T2
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1007],b[107][107];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int j=1;j<=m;++j){
		if(j%2==1){
			for(int i=1;i<=n;++i){
				b[i][j]=a[n*(j-1)+i];
			}
		}else{
			for(int i=n;i>=1;--i){
				b[i][j]=a[n*(j-1)+n-i+1];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(b[i][j]==t){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
//seat.ans froepen( int mian() cout<<i<<" "<<j printf("%d%d",i,j) 
