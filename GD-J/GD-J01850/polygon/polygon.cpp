#include <bits/stdc++.h>
using namespace std;
int a[5010],n,ma=-1,mal=-1,ans;
int main()
{
	//freopen("polygon.in","r",stdin)
	//freopen("polygon.out","w",stdout)
	scanf("%d" ,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d" ,&a[i]);
		s+=a[i];
		if(a[i]>ma)
		{
			ma=a[i];
		}
	}
	if(s>2*ma) printf("%d" ,1)
	else printf("%d" ,0)
	//fclose("polygon.in")
	//fclose("polygon.out")
	return 0; 
}
