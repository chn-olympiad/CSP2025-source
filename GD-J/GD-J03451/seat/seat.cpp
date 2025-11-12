#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int ansn,ansm;
struct T
{
	int id,grade;
}a[105];
bool cmp(T x,T y)
{
	return x.grade>y.grade;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i].grade;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			if(i%n==0)
			{
				ansm=i/n;
			}
			else
			{
				ansm=i/n+1;
			}
			if(ansm%2==0)
			{
				if(i%n==0)
				{
					ansn=1;
				}
				else
				{
					ansn=n-i%n+1;
				}
			}
			else
			{
				if(i%n==0)
				{
					ansn=n;
				}
				else
				{
					ansn=i%n;
				}
			}
			break;
		}
	}
	cout << ansm << " " << ansn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
