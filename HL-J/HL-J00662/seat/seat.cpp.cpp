#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,rc,tj=0;
	cin>>n>>m>>rc;
	for(int i=0;i<n*m-1;i++){
		long long a;
		cin>>a;
		if(a>rc){
			tj++;
		}
	}
	long long y=(tj+1)%n,s=(tj+1)/n;
	if(y==0){
		if(s%2==0){
			cout<<s<<" 1";
			return 0;
		}
		if(s%2!=0){
			cout<<s<<" "<<n;
			return 0;
		}
	}
	else{
		if(s%2==0){
			cout<<s+1<<" "<<y;
			return 0;
		}
		if(s%2!=0){
			cout<<s+1<<" "<<n-y+1;
			return 0;
		}
	}
	return 0;
}
