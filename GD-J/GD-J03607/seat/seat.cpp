#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],amx=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])
			amx++;
	}
	cout<<(amx+n)/n<<' ';
	if((amx+n)/n%2==1)
		cout<<amx%n+1;
	else
		cout<<n-(amx%n+1);
	return 0;	
} 
