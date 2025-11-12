#include<bits/stdc++.h>
using namespace std;
int n,m,a,R,seat;
int hang,lei;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	seat=1;
	int ren=n*m-1;
	while(ren--)
	{
		cin>>a;
		if(a>R)seat++;
	}
	lei=(seat-1)/n+1;
	hang=seat%n;
	if(!hang)hang=n;
	if(lei%2==0)
	{
		hang=n+1-hang;
	}
	cout<<lei<<' '<<hang;
	return 0;
}
