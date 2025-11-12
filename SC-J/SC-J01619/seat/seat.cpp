#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
int a[N*N];
int p[N*N];
int pos[N][N];
signed main(){
#ifndef DEBUG
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#endif
//	freopen("seat\\seat3.in","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i],p[i]=i;
	sort(p+1,p+n*m+1,[&](int i,int j){
		return a[i]>a[j];
	});
	for (int r=1,tot=1;r<=m;r++){
		if (r&1){
			for (int c=1;c<=n;c++){
				pos[c][r]=p[tot++];
			}
		}
		else for (int c=n;c>=1;c--)
			pos[c][r]=p[tot++];
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (pos[i][j]==1){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
}
/*
2 2
99 100 97 98

*/