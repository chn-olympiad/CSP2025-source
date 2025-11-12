#include<bits/stdc++.h>
using namespace std;
int main()
{
    filename.cpp(seat.in,"w",seat.out );
    int n,m,a[105],c=0,r=0;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		if (a[1]>a[i]){
			n--;
		}
	}
	cout<<n<<" "<<m;
	return 0;
}
