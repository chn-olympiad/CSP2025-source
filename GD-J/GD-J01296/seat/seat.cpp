#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int b[11][11];
	int a[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	double num=a[1];
	double k;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==num)
		{
			k=1+(m*n-i);
			break;
		}
	}
	int l=ceil(k/n);
	int h;
	if(l%2==0)
	{
		h=n-abs(k-l*n);
	}
	else
	{
		h=k-(l-1)*n;
	}
	cout<<l<<"  " <<h<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

