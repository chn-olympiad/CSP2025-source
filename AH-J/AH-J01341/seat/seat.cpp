/*AK CSP-J*/
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[15][15],s[110],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	long long t=s[1];
	sort(s+1,s+n*m+1,greater<long long>());
	for(int i=1;i<=m;i++){
		if(i%2!=0)for(int j=1;j<=n;j++)a[j][i]=++cnt;
		else for(int j=n;j>=1;j--)a[j][i]=++cnt;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[a[i][j]]==t){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
