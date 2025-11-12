#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100005],x,y,z,t,ans;
struct member{
	int a,b,c;
}mem[100005];
bool cmp(member x,member y)
{
	return x.a > y.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int test = 1;test <= t;test++)
	{
		ans = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> mem[i].a >> mem[i].b >> mem[i].c;
		}
		sort(mem + 1,mem + 1 + n,cmp);
		for (int i = 1;i <= n / 2;i++)
		{
			ans += mem[i].a;
		}
	}
	cout << ans;
	return 0;
}
