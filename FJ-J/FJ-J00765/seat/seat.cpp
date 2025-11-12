#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	int a[20][20];
	int pm[110];
	cin>>n>>m;
	for (int i=0;i<n*m;i++)
	{
		cin>>pm[i];
	}
	r=pm[0];
	sort(pm,pm+n*m);
	int h=1,l=1;
	//n=h,m=l;
	for (int i=n*m-1;i>=0;i--)
	{
		//cout<<endl<<l<<" "<<h;
		if (pm[i]==r){
			cout<<l<<" "<<h;
			break;
		}
		if (l%2==1 && h!=n){
			h++;
		}
		else if (l%2==1 && h==n)
		{
			l++;
		}
		else if (l%2==0 && h!=1)
		{
			h--;
		}
		else if (l%2==0 && h==1)
		{
			l++;
		}
	}
	return 0;
}
