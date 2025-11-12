#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
char str[MAXN];
char nums[MAXN];
int pnums = 0;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) if (isdigit(str[i])) nums[pnums++] = str[i];
	
	sort(nums, nums + pnums, greater<char>());
	for (int i = 0; i < pnums; i++) putchar(nums[i]);
	
	return 0;
} 
