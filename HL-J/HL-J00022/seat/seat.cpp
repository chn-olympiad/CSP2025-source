#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000];
int my,x;
int p,hang,lie;
bool cnt(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int len=n*m;
	for(int i=0;i<len;++i)
	{
		scanf("%d",&a[i]);
	}
	my=a[0];
	sort(a,a+len,cnt);
	for(int i=0;i<=len;i++)
	{
		if(a[i]==my)
		{
			p=i+1;
			hang=(p%n)+(p/n);
			if(hang%2==1)
			{
				lie=p-(hang-1)*n;
			}
			else
			{
				lie=m-p+(hang-1)*n+1;
			}
			cout<<hang<<" "<<lie;
		}
	}
	return 0;
}
