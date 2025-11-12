#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],cnt=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(long long i=2;i<=n*m;i++)cin>>a[i],cnt+=a[i]>a[1];
	long long lie=ceil(cnt*1.0/n);
	cnt-=(lie-1)*n;
	if(lie%2==1){
		cout<<lie<<" "<<cnt;
	}
	else cout<<lie<<" "<<n+1-cnt;
	return 0;
}
