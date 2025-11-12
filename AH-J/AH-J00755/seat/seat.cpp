#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y,c=1;
struct node
{
	int x,f;
}a[1000000];
bool cmp(node A,node B)
{
	return A.x>B.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].f=1;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].x;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].f)
			c=i;
	cout<<(c+m-1)/m;
	if((c+m-1)/m%2==1)
		cout<<" "<<c-((c+m-1)/m-1)*m;
	else
		cout<<" "<<m-(c-((c+m-1)/m-1)*m)+1;
	
	
	return 0;
}
