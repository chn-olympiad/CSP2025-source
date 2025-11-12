#include <bits/stdc++.h>
using namespace std;
long long arr[13][13];
long long n,m;
long long a[105];
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n*m;i++) cin>>a[i];
	long long seat_R=a[0];
	sort(a,a+n*m);
	long long arr[13][13];
	for(long long i=1,h=n*m-1;i<=m;i++){
		if(i%2!=0){
			for(long long j=0;j<n;j++){
				arr[j][i-1]=a[h];
				h--;
			}
		}else{
			for(long long j=n-1;j>=0;j--){
				arr[j][i-1]=a[h];
				h--;
			}
		} 
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<m;j++){
			if(arr[i][j]==seat_R){
				cout<<j+1<<' '<<i+1<<endl;
				return 0;
			}
		}
	}
	return 0;
}
