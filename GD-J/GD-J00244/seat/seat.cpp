#include<bits/stdc++.h>
using namespace std;
long long a,b,n,m,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a){
			t++;
		}
	}
	if((t/n)%2==0){
		cout<<t/n+1<<" "<<t%n+1;
	}else{
		cout<<t/n+1<<" "<<n-(t%n);
	}
	return 0;
}
