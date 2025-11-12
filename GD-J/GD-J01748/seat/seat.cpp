#include<bits/stdc++.h>
using namespace std;
long long n,m,ji,fu[101],diyi,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n*m;i++){
		cin>>diyi;
		fu[diyi]+=1;
		if(i==0){
			R=diyi;
		}
	}
	for(long long i=100;i>=1;i--){
		ji+=fu[i];
		if(i==R){
			ji-=1;
			cout<<ji/n+1<<" ";
			if(ji%(2*n)<n){
				cout<<ji%(2*n)+1;
			}else{
				cout<<(2*n-1)-(ji%(2*n))+1;
			}
			return 0;
		}
	}
	return 0;
}
