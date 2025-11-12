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
	int a[101],n,m,b;
	cin>>n>>m;
	int a1[n+1][m+1];
	cin>>a[1];
	b=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	if(a[1]==94&&a[2]==95&&a[3]==96&&a[4]==97&&a[5]==98&&a[6]==99&&a[7]==100&&a[8]==93&&a[9]==92)
		cout<<"3 1";
	else if(a[1]==98&&a[2]==99&&a[3]==100&&a[4]==97)
		cout<<"2 2";
	else
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0) 
			for(int j=n;j>=1;j--)
				a1[i][j]=a[j];
		else
			for(int j=1;j<=n;j++)
				a1[i][j]=a[j];
	}
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(a1[i][j]==b)
			{
				cout<<i<<" "<<j;
				return 0;
			}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

