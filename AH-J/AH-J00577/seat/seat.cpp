#include<bits/stdc++.h>
using namespace std;
int n,m,seat=0,a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n*m;i++){
		if(a[1]<=a[i]){
			seat++;
		}
	}
	cin>>seat;
	int lin=(seat/(2*n))*2;
	if (seat%(2*n)>n){
		cout<<lin+2<<" "<<2*n-seat%(2*n)+1;
	}
	else{
		cout<<lin+1<<" "<<seat%(2*n);
	}
	return 0;
}
//RP++ 
