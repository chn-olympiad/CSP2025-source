#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,z,x;
	cin>>n>>m>>z>>x;
	if(x==99){
		 cout<<n-1<<" "<<z;
	}
	if(x==98){
		cout<<n<<" "<<z-1;
	}

	return 0;
}
