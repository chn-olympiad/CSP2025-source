#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	cin>>a;
	int b,k=1;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a)
		k++;
	}
	if(k%n==0){
		cout<<k/n<<" ";
		if(k/n%2==0)
		cout<<1;
		else
		cout<<n;
	}
	else{
		cout<<k/n+1<<" ";
		if((k/n+1)%2==0)
		cout<<n-k%n+1;
		else
		cout<<k%n;
	}
	return 0;
}
