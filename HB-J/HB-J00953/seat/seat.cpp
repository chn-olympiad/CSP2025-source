#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;cin>>n>>m;
	int a[m*n];
	for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	int r=a[0];
	int l=m*n;
	sort(a,a+l);
	int d=0;
	for(int i=m*n-1;i>=0;i--){
		if(r==a[i]) d=i;
	}
	int b=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b==d) cout<<m<<" "<<n;
			b++;

		}

	}cout<<" "<<d;
	return 0;
}
