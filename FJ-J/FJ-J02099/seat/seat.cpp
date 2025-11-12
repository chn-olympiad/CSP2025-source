#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[105];
int b[15][15];
int p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;++j)
		for(int i=1;i<=n;++i) b[i][j]=a[n*(j-1)+i];
	for(int i=2;i<=n;i+=2)
		for(int j=1;j<=n/2;++j) swap(b[j][i],b[n-j+1][i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(b[i][j]==p){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

