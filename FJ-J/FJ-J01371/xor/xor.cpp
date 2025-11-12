#include<bits/stdc++.h>
using namespace std;
struct A{
	int x,y;
}b[500010];
int n,m,a[500010],l=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if((a[j]^a[j-i])==m)
			{
				b[l].x=j-i+1;
				b[l].y=j;
				for(int p=1;p<l;p++)
				{
					if((b[p].y>=b[l].y&&b[p].x<=b[l].y)||(b[l].y>=b[p].y&&b[l].x<=b[p].y)||(b[p].y<=b[l].y&&b[p].x>=b[l].x))
					{
						b[l].x=0;
						b[l].y=0;
						l--;
						break;
					}
				}
				l++;
			}
		}
	cout<<l-1;
	return 0;
}
