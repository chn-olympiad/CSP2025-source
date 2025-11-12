#include <bits/stdc++.h>

using namespace std;
bool findbiggest(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+n*m,findbiggest);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==r)
		{
			r=i+1;
			break;
		}
	}
	int s=r/n;
	r=r%n;
	if(r!=0)
		s++;
	else
		r=n;
	if(s%2==0)
		r=n-r+1;
	cout<<s<<" "<<r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
