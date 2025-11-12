#include<bits/stdc++.h>
using namespace std;
long long a[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,rc,tj=0;
	cin>>n>>m>>rc
	for(int i=0;i<=n*m-1;i++){
			long long a;
			cin>>a
			if(a>>rc){
				tj++;
			}
	}
	cout<<tj;
	long long y=(tj+1)%n,s=(tj+1)/n;
	if(y==0){
		if(s%2==0){
			cout<<s<<"1";
		}
		if(s%2!=0){
			cout<<s<<"4";
		}
	}
	else{
	if(s%2==0){
			cout<<s+1<<" "<<y;
		}
		if(s%2!=0){
			cout<<s+1<<""<<;
		}
	}
	return 0;
}
