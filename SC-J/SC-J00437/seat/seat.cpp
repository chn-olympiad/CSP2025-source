#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101];
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
		cin>>a[i];
	int a1;
	a1=a[1];
	sort(a+1,a+m*n+1);
	int x=0;
	for(int i=m*n;i>=1;i--)
	{
		x++;
		if(a[i]==a1) break;
	}
	int s1,s2;
	s1=x/n;
	s1++;
	if(x%n==0) s1--;
	if(s1%2==0)
	{
		s2=n-x%n+1;
		if(x%n==0) s2=1;
	}
	else
	{
		s2=x%n;
		if(x%n==0) s2=n;
	}
	
	cout<<s1<<" "<<s2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}