//2024tysc0092 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,rp=1,gd,x,y;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>gd;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>gd){
			rp++;
		}
	}
	x=(rp-1)/n+1;
	y=(rp-1)%n+1;
	if(x&1){
		cout<<x<<" "<<y;
	}else{
		cout<<x<<" "<<n-y+1;
	}
	return 0;
}
/*
Ò»Ûç 
*/
