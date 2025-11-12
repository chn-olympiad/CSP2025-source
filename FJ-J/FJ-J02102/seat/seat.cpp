#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct p
{
	int id,f;
}s[1000];
bool cmp(p a,p b)
{
	return a.f>b.f; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].f;
		s[i].id=i;
	}
	sort(s+1,s+n*m+1,cmp);
	int y=0;
	for(int i=1;i<=n*m;i++)
	{
		if(s[i].id==1)y=i;
	}
	int h=(y-1)/m+1,l=(y-1)%n+1;
	if(h%2==0)l=n+1-l;
	cout<<h<<' '<<l; 
	return 0;
}
