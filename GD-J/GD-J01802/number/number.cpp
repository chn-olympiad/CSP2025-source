#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
namespace GY2025YY
{
	const int N=1000003;
	int n,cnt[1000];
	char s[N];
	int main()
	{
		freopen("number.in", "r", stdin);
		freopen("number.out","w",stdout);
		scanf("%s",s+1);
		n=strlen(s+1);
		for (int i=1;i<=n;++i)
		{
			if (s[i]>='0' && s[i]<='9')
				++cnt[s[i]-'0'];
		}
		for (int i=9;i>=0;--i)
		{
			while (cnt[i]--)
				printf("%d",i);
		}
		return 0;
	}
}
int main()
{
	return GY2025YY::main();
}

