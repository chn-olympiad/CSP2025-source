#include <bits/stdc++.h>
using namespace std;
long long R,n,m,num,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> num;
	for(long long i=1;i<n*m;i++)
	{
		cin >> x;
		if(x>num)
			R++;
	}
	x=R/n;
	y=R-(x*n);
	if(x%2==0){
		cout << (x+1) << " " << (y+1) << endl;
	}
	else{
		cout << (x+1) << " " << (n-y) << endl;
	}
	return 0;
}
