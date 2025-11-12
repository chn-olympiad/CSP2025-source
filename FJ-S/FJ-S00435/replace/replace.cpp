#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		srand(time(0));
		int w=rand()%1000005;
		printf("%d\n",w);
	}
	return 0;
}
