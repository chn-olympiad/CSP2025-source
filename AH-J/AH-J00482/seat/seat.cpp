#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,me,sit=1;
	scanf("%d%d%d",&n,&m,&me);
	for(int i=1;i<n*m;i++)
	{
		int now;
		scanf("%d",&now);
		if(now>me)
		{
			sit++;
		}
	}
	
	int lie=(sit-1)/n+1;
	int hang=(lie%2==0 ? n-sit%n+1 : sit%n);
	if(hang==0) hang=n;
	if(hang>n) hang=1;
	cout<<lie<<' '<<hang<<'\n';
	
	return 0;
}
