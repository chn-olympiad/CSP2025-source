#include <bits./stdc++.h>
using namespace std;


int main(){
	int n,m;
	int r=0;
	int b[10005];
	int a[10005][10005];	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin  >>n >> m;
	int s=n*m;
	for (int i=0;i<s;i++)
	{
		cin >> b[i];
		if(b[i]>=b[1])
			r=r+1;
		
	}
	int p=r%(2*n);
	int q=r/(2*n);
	int x=2*q;
	if (p<=n&&p>0);
	{
		x=x+1;
		cout << x << ' '<< p;
	}
	if(p<2*n&&p>n);
	{
		x=x+2;
		cout << x <<' '<< 2*n-p+1;
	}
	if(p==0){
		cout << x <<' '<< '1';
	}
	return 0;
}