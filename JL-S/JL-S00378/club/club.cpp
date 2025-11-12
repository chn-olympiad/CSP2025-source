#include<bits/stdc++.h>
using namespace std;
struct ttt
{
	int aa,dd,bb;
};
ttt c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	int b;
	int l=0;
	for(int i=0;i<a;i++)
	{
		cin>>b;
		for(int j=0;j<b;j++)
		{
			for(int w=0;w<3;w++)
			{
				cin>>c[j*3+w].aa;
				c[w].dd=j;
				c[w].bb=w;
			}
		}
		for(int j=0;j<3*b;j++)
		{
			for(int w=j+1;w<3*b;w++)
			{
				int r=c[j].aa+c[w].aa;
				if(c[j].bb != c[w].bb && c[j].dd != c[w].dd && r>l)
				{
					l=r;
				}
			}
		}
		cout<<l<<"\n";
	}
	return 0;
}
