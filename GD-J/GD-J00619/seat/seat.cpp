#include<bits/stdc++.h>
using namespace std;
int n,m,num,ansn,ansm;
struct node
{
	int a,id;
}s[1005];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].a;
		s[i].id=i;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) 
		if(s[i].id==1)
		{
			num=i;
			break;
		}
	ansn=(num-1)/n+1;
	if(num%(n*2)>=1&&num%(n*2)<=n)
	{
		ansm=num-(ansn-1)*n;	
	} 
	else
	{
		ansm=ansn*n-num+1;
	}
	cout<<ansn<<" "<<ansm<<endl;
	return 0;
}
