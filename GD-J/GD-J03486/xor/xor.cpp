#include<bits/stdc++.h>
using namespace std;
int a;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,now=-1;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a);
		if(now==-1)
		{
			now=a;
		}
		else
		{
			now^=a;
		}
		if(now==k)
		{
			++ans;
			now=-1;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

