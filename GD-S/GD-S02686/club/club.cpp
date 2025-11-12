#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
	int a,b,c;
};

bool cmp(node a,node b)
{
	return a.a>b.a;
}

int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(t;t>=1;--t)
	{
		int n,ans=0;
		cin >> n;
		for(int i=1;i<=n;++i)
		{
			int b,c,d;
			cin >> b >> c >> d;
			ans+=max(b,max(c,d));
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
