#include<bits/stdc++.h>
using namespace std;
//3 3
//94 95 96 97 98 99 100 93 92
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[10000];
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int p=a[1];
	int len=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			len=i;
		}
	}
	int q=0;
	if(len%m==0)
	{
		cout << len/m << " ";
		q=len/m;
	}
	else
	{
		cout << len/m+1 << " ";
		q=len/m+1;
	}
	
	if(q%2==0)
	{
		cout << n-(len-(q-1)*n-1);
	}
	else
	{
		cout << len-(q-1)*n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
