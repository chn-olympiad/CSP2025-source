#include<bits/stdc++.h>
using namespace std;
int n,m,in[105];
//int a[105][105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;++i)
	{
		cin>>in[i];
	}
	int a1=in[0];
	sort(in,in+n*m,cmp);
	int dic=1,x=0,y=0;
	for(int i=0;i<n*m;++i)
	{
		if(in[i]==a1)
		{
			cout<<y+1<<' '<<x+1;
			break;
		}
		//a[x][y]=in[i];
		x+=dic;
		if(x==n||x<0)
		{
			dic=-dic;
			++y;
			if(x==n)
			{
				--x;
			}
			else
			++x;
		}
	}
	/*cout<<endl;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
