#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,hang,lie,cnt,t;
	scanf("%d",m,n);
	for(int i=0;i<m*n;i++)
	{
		scanf("%d",a[i]);
	}
	cnt=a[0];
	for(int i=1;i<=m*n-1;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
		}
	}
	for(int c=0;c<m*n;c++)
	{
		if(a[c]==cnt);
			t=c;
	}
	lie=floor(t/n)+1;
	if(t%2==1)
	{
		if((t+1)%m==0)
			hang=m;
		else
			hang=(t+1)%m;
	}
	else
	{
		if((t+1)%m==0)
			hang=1;
		else
			hang=m-(t+1)%m;
	}
	printf("%d",lie,hang);
	return 0;
}
