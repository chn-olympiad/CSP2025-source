#include<bits/stdc++.h>
using namespace std;
long long a[1000];
long long ans[100][100];
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)cin>>a[i];
	long long c=a[1];
	sort(a+1,a+1+n*m,greater<long long>());
	long long x=1;
	for(long long j=1;j<=m;j++){
		if(j%2==1){
			for(long long i=1;i<=n;i++){
				ans[i][j]=a[x];
				if(a[x]==c){
					cout<<j<<' '<<i;
					return 0;
				}
				x++;
			}
		}
		else{
			for(long long i=n;i>=1;i--){
				ans[i][j]=a[x];
				if(a[x]==c){
					cout<<j<<' '<<i;
					return 0;
				}
				x++;
			}
		}
	}
	return 0;
}