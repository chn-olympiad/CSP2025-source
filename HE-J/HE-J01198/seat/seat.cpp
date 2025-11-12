#include<bits/stdc++.h>
using namespace std;
int n,m,a[220],r;
inline bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*m;i ++)scanf("%d",&a[i]);
	r = a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i <= n;i ++) {
		int k = 0;
		for(int j = 1;j <= m;j ++)
		{
			k = (i-1)*n+j;
			if(a[k] == r)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		k=0;
		i++;
		if(i > n)break;
		for(int j = m;j >= 1;j --)
		{
			k = (i-1)*n+(m-j+1);
			if(a[k] == r)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
