#include <iostream>
#include <cstring>
using namespace std;
namespace GY2025YY
{
	const int N=200003;
	string t1,t2,a[N],b[N];
	int n,m,ans;
	inline bool check(int id)
	{
		if (t1.find(a[id])!=EOF)
		{
			int pos=t1.find(a[id]);
			return t1.replace(pos,a[id].size(),b[id])==t2;
		}
		else return 0;
	}
	int main()
	{
		freopen("replace.in", "r", stdin);
		freopen("replace.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cin>>n>>m;
		for (int i=1;i<=n;++i)
			cin>>a[i]>>b[i];
		while (m--)
		{
			cin>>t1>>t2;ans=0;
			for (int i=1;i<=n;++i)
				if (check(i)) ++ans;
			printf("%d\n",ans);
		}
		return 0;
	}
}
int main()
{
	return GY2025YY::main();
}

