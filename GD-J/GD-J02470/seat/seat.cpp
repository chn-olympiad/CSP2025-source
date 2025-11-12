#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m;
struct Node
{
	int val,pos;
}a[N];
bool cmp(Node A,Node B)
{
	return A.val>B.val;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].val);
		a[i].pos=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1;
	int y=1;
	int d=1;
	int id=1;
	while(1)
	{
		if(a[id].pos==1)
		{
			cout<<y<<' '<<x;
			return 0;
		}
		if(d==1)
		{
			if(x<n) x++,id++;
			else y++,d=2,id++;
		}
		else
		{
			if(x>1) x--,id++;
			else y++,id++,d=1;
		}
	}
}
