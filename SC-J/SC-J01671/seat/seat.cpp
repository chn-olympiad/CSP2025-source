#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],sums,cnt,f;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sums=n*m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	cnt=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++){
		if(f==0){
			f=1;
			for(int j=1;j<=n;j++){
				if(a[sums]==cnt)cout<<i<<" "<<j;
				sums--;
			}
		}else{
			f=0;
			for(int j=n;j>=1;j--){
				if(a[sums]==cnt)cout<<i<<" "<<j;
				sums--;
			}
		}
	}
	return 0;
}