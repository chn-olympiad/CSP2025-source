#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110000][110000],sum=1;
int main(){
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w",stdout);
	cin>>n>>m;
	cin>>a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>a[1][1])sum++;
		}
	} 
	if(sum%n==1)cout<<sum/n+1<<' ';
	else cout<<sum/n<<' ';
	if(sum/n%2==0)cout<<n-sum%n+1;
	else cout<<sum%n;
	return 0;
}
