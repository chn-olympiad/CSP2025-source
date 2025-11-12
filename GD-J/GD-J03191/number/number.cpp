#include <iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int n[1005],o = 1;
	for(int i = 0;i < a.length();i++)
	{
		for(int j = 0;j <= 9;j++)
		{
			if(i == j)
			{
				n[o] = j;
				o++;
				break;
			}
		}
	}
	int b = 0;
	while(b == 0)
	{
		int a = 1;
		while(a != (o-1))
		{
			if(n[a] < n[a+1])
			{
				int t = n[a];
				n[a] = n[a+1];
				n[a+1] = t;
				b = 1;
			}
			a++;
		}
	}
	for(int i = 1;i < o;i++)
	{
		cout << n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

