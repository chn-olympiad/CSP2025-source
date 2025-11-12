#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h;
	cin>>n>>m;
	int s[n*m];
	for (int i=0;i<n*m;i++)
	{
		cin>>s[i];
	}
	h=s[0];
	sort(s,s+n*m,cmp);
	for (int i=0;i<n*m;i++)
	{
		if(s[i]==h) h=i+1;
	}
	cout<<(h-1)/n+1<<" ";
	if(((h-1)/n+1)%2==0)
	{
		cout<<n+1-(h%n==0)*n-h%n;
	}
	else
	{
		cout<<h%n+(h%n==0)*n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
