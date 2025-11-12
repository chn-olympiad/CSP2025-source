#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m]={0};int k;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	k=a[0];
	sort(a,a+n*m,cmp);int s;
	for(int i=0;i<n*m;i++)
	{
		if(a[i] == k)
		{
			s = i;
		}
	}int w=0;s++;
	while(s>n)
	{
		s-=n;
		w++;
	}
	cout<<++w<<' ';
	if(w%2==1)
	{
		cout<<s;
	}
	else
	{
		if(s==n)
		{
			cout<<n;
		}
		else
		{
			cout<<n-s+1;
		}
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
