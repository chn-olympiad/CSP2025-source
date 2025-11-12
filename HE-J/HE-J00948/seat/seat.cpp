#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,e,f=1,g;
int a[110];
bool cmp(int g,int f)
{
	return g>f;
}
int main()
{
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
//			cin>>a[i];
		scanf("%d",&a[i]);
	}
	d=a[1];
	g=n*m;
	sort(a+1,a+1+g,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==d)
		{
			e=i;
//			cout<<e<<endl;
			break;
		}
	}
	for (int i=1;i<=n;i+=0)
	{
		for(int j=1;j<=m;j+=0)
		{
			if(f==e)
			{
				cout<<j<<" "<<i;
				return 0;
			}
			else if (c==1)
			{
				if (i!=1)
					i--;
				else if (i==1)
				{
					j++;
					c=0;
				}
				f++;
//				cout<<i<<" "<<j<<endl;
			}
			else if (c==0)
			{
				if (i==n)
				{
					j++;
					c=1;
				}
				else
				{
					i++;
				}
				f++;
//				cout<<i<<" "<<j<<endl;
			}
//			
		}
	}
	return 0;
	fclose(stdin);fclose(stdout);
} 
