#include <iostream>
#include <algorithm>
using namespace std;

int a[105];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","u",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	int k = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int id;
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == k)
		{
			id = i;
			break;
		}
	}
	int s;
	if(id % n == 0) s = id / n - 1;
	else s = id / n;
	int mod = id % n + 1;
	if(s % 2 == 0)
	{
		if(id % n == 0) cout << s + 1 << " " << n;
		else cout << s + 1 << " " << mod - 1;
	}
	else 
	{
		if(id % n == 0) cout << s + 1 << " " << 1;
		else cout << s + 1 << " " << n - mod + 2;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
