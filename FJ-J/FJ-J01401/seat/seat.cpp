#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int cmp(int aa, int bb)
{
	return aa>bb;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int a[n*m+1] = {0};
	
	for(int i = 1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int pos = a[1];
	
	
	sort(a+1,a+n*m+1,cmp);
	int ming = 0;
	for(int i = 1;i<=n*m;i++)
	{
		
		if(a[i] == pos)
		{
			ming = i;
		}
	}
	
	
	int lie = 0;
	
	
	if(ming%n == 0)
	{
		lie = ming/n;
	}
	else
	{
		lie = ming/n+1;
	}
	
	int hang = 0;
	if(lie % 2 == 1)
	{
		hang = ming%n;
		if(hang == 0)
		{
			hang += n*lie;
		}
	}
	else if(lie % 2 == 0)
	{
		hang = (n+1)-(ming%n);
	}
	cout << lie << " " << hang;
	
	
	return 0;
}

