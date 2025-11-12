#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;
int a[N];

int main () 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	int ret = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==k)
		{
			ret++;
		}
	}
	if(ret==0)printf("2");
	else printf("%d",ret);
	return 0;
}
