#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==x){
				cout<<i<<' ';
				if(i&1)	cout<<j;
				else	cout<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}