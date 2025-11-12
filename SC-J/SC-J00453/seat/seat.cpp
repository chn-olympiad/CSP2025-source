#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,a[N*N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int tar=a[1];
	sort(a+1,a+n*m+1,cmp);
	int th,line=1,col=1;
	string d="down";
	for(th=1;a[th]!=tar;th++)
	{
		if(line==1&&col%2==0)
		{
			col++;
			d="down";
		}
		else if(line==n&&col%2!=0)
		{
			col++;
			d="up";
		} 
		else
		{
			line+=((d=="up")?-1:1);
		}
	}
	cout<<col<<' '<<line<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}