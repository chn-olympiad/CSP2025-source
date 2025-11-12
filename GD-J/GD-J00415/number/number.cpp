#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int shuzi[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string zifu;
	cin >> zifu;
	int xiab = 0;
	for (int i = 0;i < zifu.size();i++)
	{
		if (zifu[i] >= '0' && zifu[i] <= '9')
		{
			shuzi[xiab] = zifu[i] - '0';
			xiab++;
		}
	}
	sort(shuzi,shuzi + xiab);
	for (int i = xiab - 1;i >= 0;i--)
	{
		cout << shuzi[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
