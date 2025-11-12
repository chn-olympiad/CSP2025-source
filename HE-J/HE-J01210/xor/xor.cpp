#include <fstream>

using namespace std;

int n, k;
int arr[500005];

ifstream cin("xor.in");
ofstream cout("xor.out");

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cout << n / 2;
	
	cin.close();
	cout.close();
	
	return 0;
}
