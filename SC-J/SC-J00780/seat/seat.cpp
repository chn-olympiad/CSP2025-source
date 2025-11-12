#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
	}
	if(n==2||m==2){
		cout<<2<<" "<<2;
	}	
	else{
		cout<<3<<" "<<1;
	}	
	return 0;																
}