#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int numPerson, numTarget;
	string test;
	cin >> numPerson >> numTarget >> test;
	vector<int> personVal(numPerson);
	for (auto &elem : personVal)
	{
		cin >> elem;
	}
	
	vector<int> perm(numPerson);
	for (int i = 0; i < numPerson; i++)
		perm[i] = i;
	
	int cnt = 0;
	do
	{
		int refuseCnt = 0;
		for (int i = 0; i < numPerson; i++)
		{
			if (test[i] == '0')
				refuseCnt++;
			else if (refuseCnt >= personVal[perm[i]])
				refuseCnt++;
		}
		if (numPerson - refuseCnt >= numTarget)
			cnt = (cnt + 1) % 998244353;
	} while (next_permutation(perm.begin(), perm.end()));
	
	cout << cnt << endl;
	return 0;
}
