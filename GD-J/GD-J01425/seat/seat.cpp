#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct student
{
	int id,f;
}a[N];
bool cmp(student a,student b)
{
	return a.f>b.f;
}
int n,m,h=1,l=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].f;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{	
		if(a[i].id==1)
		{
			cout<<l<<" "<<h;
			break;
		}
		if(h%n==0&&l%2==1) 
		{
			l++;
			continue;
		}
		else if(h%n==1&&l%2==0) 
		{
			l++;
			continue;	
		}		
		if(l%2==1) h++;
		else h--;
	}
	return 0;
}
