#include <fstream>
#include <cstdio>
using namespace std;
long long a[10];
int main()
{
	freopen("number.in", "r", stdin);
	ofstream fout("number.out");
	int x;
 	while (scanf("%1d", &x) != EOF)
	{
		a[x] ++;
	}
	for (int i = 9; i >= 0; i --)
	{
		for (int j = 1; j <= a[i]; j ++)
		{
			fout << i;
		}
	}
	return 0;
} 
