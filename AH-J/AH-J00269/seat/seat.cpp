#include <bits/stdc++.h>
using namespace std;
int n,m;
struct S
{
	int num,id;
}s[205];
bool cmp(S a,S b)
{
	return a.num>b.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].num;
		s[i].id=i;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(s[i].id==1)
		{
			int a=i/n+(i%n!=0),b;
			if(a%2==1) b=i-(a-1)*n;
			else b=n-(i-(a-1)*n)+1;
			cout<<a<<" "<<b;
			return 0;
		}
	}			
	return 0;
}
