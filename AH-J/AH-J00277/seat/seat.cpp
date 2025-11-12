#include<bits/stdc++.h>
using namespace std;
long long a[102];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,x,t=1;
	cin>>n>>m;
	cin>>a[1];
	x=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>x){
			t++;
		}
	}
	if(t%n==0){
		if((t/n)%2==0)
			cout<<t/n<<" 1";
		else
			cout<<t/n<<" "<<n;
	}
	else{
		if((t/n)%2==0)
			cout<<t/n+1<<" "<<t%n;
		else
			cout<<t/n+1<<" "<<n+1-(t%n);
	}	
	return 0;
}
