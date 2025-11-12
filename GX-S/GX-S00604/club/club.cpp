#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,l[3];
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int a,b,c;
		int S=0;
		while(T--)
		{
			scanf("%d%d%d",&a,&b,&c);
			S+=max(max(a,b));
		}
		cout<<S<<"\n";
	}
	return 0;
}
