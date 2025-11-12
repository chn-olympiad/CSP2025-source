#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long m,n;
	long long a,x,seat=0,lseat=0;
	cin>>m>>n>>a;
	while(cin>>x){
		if(x>a){
			seat++;
		}else{
			lseat++;
		}
	}
	int sum=1-seat;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(sum==1){
				if(i%2==0){
					cout<<i<<" "<<n-j+1;
				}else{
					cout<<i<<" "<<j;
				}
				return 0;
			}
			sum++;
		}
	}
	return 0;
}
