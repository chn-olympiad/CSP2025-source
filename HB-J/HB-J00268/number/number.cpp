#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	int arr[1000005] = {};
	int id = 0;
	int num = s.size();
	
	for(int i = 0; i < num; i++)
		if(s[i] >= '0' and s[i] <= '9')
		{
			arr[id] = s[i] - '0';
			id ++;
		}
	
	sort(arr, arr + id + 1, cmp);
	
	for(int i = 0; i < id; i++)
		cout << arr[i];
		
	return 0;
}
