#include <iostream>
using namespace std;
long long n,m,c[505],MOD=998244353,ans=1,num;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1;i<=n;i++)
	{
		cin >> c[i];
		if(c[i]>0)
			num++;
	}
	for(int i = 1;i<=m;i++)
	{
		ans = (ans*num)%MOD;
		num--;
		num = max((long long)1,num);
	}
	cout << ans;
	return 0;
}
