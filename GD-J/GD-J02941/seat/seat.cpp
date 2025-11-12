#include<bits/stdc++.h>
using namespace std;
struct S
{
	int id,a;
}s[100005];
bool cmp(S x,S y)
{
	return x.a>y.a;
	
}
int n,m,na;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++)
	{
		cin>>s[i].a;
		if(i==1)
		{
			na=s[i].a;
		}
		s[i].id=i;
	}
	sort(s+1,s+l+1,cmp);
	for(int i=1;i<=l;i++)
	{
		if(s[i].id==1)
		{
			na=i;
			//cout<<na<<endl;
			cout<<(na-1)/n+1<<" ";
			int r=na%(2*n);
			if(r<=n&&r!=0)
			{
				cout<<r<<endl;
			}
			else{
				r=r%n;
				if(r==0)
				{
					cout<<1<<endl;
				}
				else
				{
					cout<<n-r+1<<endl;
				}
			}
		}
	}
	return 0;
 } 
