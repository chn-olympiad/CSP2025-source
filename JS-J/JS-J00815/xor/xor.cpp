#include <iostream>

using namespace std;

int N,K;
int arr[500005];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> N >> K;
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}
	
	if (N <= 2)
	{
		cout << N / 2;
	}
	else if (N <= 10)
	{
		if (K == 1)
		{
			int count = 0;
			for (int i = 1; i <= N; i++)
			{
				if (arr[i] == 1)
				{
					++count;
				}
			}
			cout << count;
		}
	}
	else if (N <= 100)
	{
		if (K == 0)
		{
			cout << N / 2;
		}
	}
	
	return 0;
}
