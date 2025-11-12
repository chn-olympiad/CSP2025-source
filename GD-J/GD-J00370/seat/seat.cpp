#include<bits/stdc++.h>
using namespace std;
int a[1001];
int a1;
int n,m;
pair<int,int> hs(int id)
{
	for(int i=1;i<=m;i++)
	{
		for(int j=(i&1?1:n);(i&1?j<=n:j>=1);(i&1?j++:j--))
		{
			id--;
			if(id==0)
			return {i,j};
		}
	}
	return {m,n};
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
	scanf("%d",&a[i]);
	a1=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==a1)
		{
			printf("%d %d",hs(i).first,hs(i).second);
			return 0;
		}
	}
}

