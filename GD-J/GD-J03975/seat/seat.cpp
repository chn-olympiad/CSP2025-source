#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,a;
	cin>>n>>m;
	cin>>t;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>t)a++;
	}
	cout<<a/n+1<<" "<<((a/n%2==0)?a%n+1:n-a%n)<<endl;
	return 0;
} 
