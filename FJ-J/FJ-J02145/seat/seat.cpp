#include<bits/stdc++.h>
using namespace std;
int n,m;
int tmp=0;
int ans1,ans2;
struct node
{
	int q,id;
}a[110];
bool cmp(node o,node p)
{
	return o.q>p.q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	tmp=n*m;
	for(int i=1;i<=tmp;i++)
	{
		cin>>a[i].q;
		a[i].id=i;
	}
	sort(a+1,a+tmp+1,cmp);
	for(int i=1;i<=tmp;i++)
	{
		if(a[i].id==1)
		{
			if(i%n==0)
			{
				ans1=i/n;
				ans2=n;
			}
			else
			{
				ans1=int(i/n)+1;
				ans2=i%n;
			}
			if(((i%n==0)?(i/n):(i/n+1))%2==0)
			{
				ans2=m-ans2+1;
			}
			break;
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
