#include<bits/stdc++.h>
using namespace std;
long long a[200];
bool xxx(long long x,long long y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=m*n;i++){
		cin>>a[i];
	}
	sort(a+2,a+(n*m)+1,xxx);
	int r=2;
	for(long long i=1;i<=m;i++){
		long long x;
		if(i%2==0){
			x=n;
		}
		else{
			x=1;
		}
		for(long long j=1;j<=n;j++){
			if(a[1]>=a[r]){
				cout<<i<<" "<<x;
				return 0;
			}
			if(i%2==1){
				x++;
			}
			else{
				x--;
			}
			r++;
		}
	}
	return 0;
} 