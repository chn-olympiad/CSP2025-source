#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[200][200],a[400];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1);
	int cnt=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++) s[i][j]=a[cnt--];
		}
		else{
			for(int j=n;j>=1;j--) s[i][j]=a[cnt--];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j]==ans){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}

