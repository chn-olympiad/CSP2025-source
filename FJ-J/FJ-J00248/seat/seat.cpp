#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a){
			s++;
		}
	}
	cout<<s/n+1<<" ";
	if((s/n+1)%2==1){
		cout<<s%n+1;
	}else{
		cout<<n-s%n;
	}
	return 0;
}
