#include <iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10005],num = 0,s;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = (i+1);j <= n;j++)
		{
			s = a[i];
			for(int p = (i+1);p <= j;p++)
			{
				s = s^a[p];
			}
			if(s == k)
			{
				num++;
				break;
			}
		}
	}
	cout << num;
	cin >> n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

