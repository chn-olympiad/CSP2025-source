#include <iostream>

using namespace std;

int n,a[3];

int main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	if(a[0] + a[1] + a[2]  > 2 * max(a[0], max(a[1], a[2])))
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}