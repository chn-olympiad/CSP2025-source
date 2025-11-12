#include<bits/stdc++.h>
using namespace std;
int n,m,x,z,cnt=1,a,b;
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>z;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>z) cnt++;
	}
	a = cnt/n;
	b = cnt%n;
	if(b==0) cout<<a<<" "<<n;
	else{
		if((a+1)%2==1){
			cout<<a+1<<" "<<b;
		}
		else{
			cout<<a+1<<" "<<n-b+1;
		}	
	}
	return 0;
}
