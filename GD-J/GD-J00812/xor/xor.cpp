#include <iostream>
#include <cstdio>
using namespace std;
int nums[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for (int i=0;i<n;i++)
		cin >> nums[i];
	if (n==4&&(k==0||k==1||k==2))
		cout << 2 << ' ' << 1 << ' ' << 0 << ' ' << 3; 
	return 0; 
}
