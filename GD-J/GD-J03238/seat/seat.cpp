#include<bits/stdc++.h>
using namespace std;
long long n,m,z,cnt=0;
long long a[1005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>z;
	a[1]=z;
	for(long long i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=m;i++){//ÁÐÊý 
		if(i%2==1){
			for(long long j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==z){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(long long j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==z){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
