#include <bits/stdc++.h>
using namespace std;
long long a[1000][1000],b[100000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,cnt=1;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>b[i];
	}
	long long r=b[1];
	sort(b+1,b+n*m+1);
	if(b[n*m]==r){
		cout<<'1'<<" "<<'1';
		return 0;
	}
	for(long long i=n;i>=1;i--){
		if(i%2==0){
			for(long long j=1;j<=m;j++){
				a[i][j]=b[cnt];
				cnt++;
				if(a[i][j]==r){
					cout<<i<<" "<<j;
				}
			}
		}
		else if(i%2==1){
			for(long long j=m;j>=1;j--){
				a[i][j]=b[cnt];
				cnt++;
				if(a[i][j]==r){
					cout<<i<<" "<<j;
				}
			}
		}
	}
}
