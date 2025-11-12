#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int n,m,a[105],g,r,c,st;
bool cmp(int a,int b)
{
	return a > b; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	g = a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i = 0;i < m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			int rk = (i*n)+j;
			if(a[rk] == g)
			{
				c = i + 1;
				if(i & 1){
					r = n - j + 1;
				}else{
					r = j;
				}
			}
		}
	}
	printf("%d %d",c,r);
	return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92
