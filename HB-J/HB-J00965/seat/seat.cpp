#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m ;
	for(int i=1;i<=n*m;i++)
		cin >> a[i];
	int s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==s)
			s=i-1;
	int x=1,y=1;
	while(s!=0)
	{
		while(s!=0 && x!=n)	s--,x++;
		if(s!=0)	s--,y++;
		while(s!=0 && x!=1)	s--,x--;
		if(s!=0)	s--,y++;
	}
	cout << y << " " << x;
	
	return 0;
}
