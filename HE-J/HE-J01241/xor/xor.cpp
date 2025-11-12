#include <iostream>
#include <algorithm> 
#include <vector>
#include <fstream>
using namespace std;
int n,k,s,u;
int main()
{
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	fin >> n,k;
	vector<long long> a(n + 5);
	for (int i = 1;i <= n;i++)
		fin >> a[i];
	for (int l1 = 1;l1 <= n;l1 ++)
	{
		for (int r1 = l1;r1 <= n;r1 ++)
		{
			long long ans = 0;
			for (int i = l1;i <= r1;i ++)
			{
				ans ^= a[i];
			}
			if (ans == k)
			{
				s++;
			}
		}
	}
	fout << s;
	return 0;
}
