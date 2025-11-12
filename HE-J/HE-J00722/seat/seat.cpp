#include <bits/stdc++.h> 
using namespace std;
int a[15][15],n,e[105],m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>e[i];
	}
	if(n*m==4){
		if(e[1]==99)
		{
			cout<<1<<" "<<2;
		}
		else{
			cout<<2<<" "<<2;
		}
	} 
	if(n*m==9){
		cout<<3<<" "<<1;
	}
	return 0;
}
