#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c=1,d,e;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a){
			c++;
		}
	}
	if(c%n==0){
		cout<<c/n<<" ";
		if((c/n)%2==1){
			cout<<n;
		}
		else {
			cout<<1;
		}
	}
	if(c%n!=0){
		cout<<c/n+1<<" ";
		if((c/n+1)%2==1){
			cout<<c%n;
		}
		else {
			cout<<n-c%n+1;
		}
	}
	
	return 0;
}
