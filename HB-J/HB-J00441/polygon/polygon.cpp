#include<bits/stdc++.h>
using namespace std;
int n,d,li[20000],bc,cnt;
void ds(int a)
{
	int shu=0;
	while(a>2)
	{
		for(int k=0;k<=a-2;k++)
		{
			for(int j=1+k;j<a;j++)
			{
				bc+=li[j];
				if(bc>li[a])
				{
					shu++;
				}
			}
			bc=0;		
		}
		a--;
	}
	cnt+=shu;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>li[i];
	}
	sort(li,li+n+1);
	for(int i=3;i<=n;i++)
	{
		ds(i);
	}
	for(int i=1;i<n;i++)
	{
		d+=li[i];
	}
		cout<<cnt%244;
	return 0;
}
