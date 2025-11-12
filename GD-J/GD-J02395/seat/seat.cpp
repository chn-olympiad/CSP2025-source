#include<bits/stdc++.h>
using namespace std;
struct node
{
	int test,number;
}a[105];
bool cmp(node x,node y)
{
	return x.test >y.test ; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,s;
	cin>>x>>y;
	s=x*y;
	for(int i=1;i<=s;i++) 
	{
		scanf("%d",&a[i].test);
		a[i].number=i;
	}
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++)
		if(a[i].number==1) 
		{
			s=i;
			int n=s/x;
			if(s%x!=0) n=n+1;
			if(n%2==1) printf("%d %d",n,(s-1)%x+1);
			else printf("%d %d",n,y-(s-1)%x);
			return 0;
		}
	
	return 0;
}
