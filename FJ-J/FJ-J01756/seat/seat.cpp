#include <bits/stdc++.h>
using namespace std;
struct student
{
	int id;
	int grade;
};
student t[105];
bool cmp(student a,student b)
{
	if (a.grade==b.grade)
	{
		return a.id<b.id;
	}
	return a.grade > b.grade;
}
int main()
{
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> t[i].grade;
		t[i].id=i;
	}
	sort (t+1,t+1+n*m,cmp);
	int s;
	for (int i=1;i<=n*m;i++)
	{
		if (t[i].id==1)
		{
			s=i;
			break;
		}
	}
	if (s%n==0)
	{
		if ((s/n)%2==0)
		{
			cout << s/n << " " << 1;
		}
		else
		{
			cout << s/n << " " << n;
		}
	}
	else if (s%n!=0)
	{
		if ((s/n+1)%2==0)
		{
			cout << s/n+1 << " " << n-s%n+1;
		}
		else
		{
			cout << s/n+1 << " " << s%n;
		}
	}
	return 0;
}
