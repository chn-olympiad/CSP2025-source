#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	ifstream cin("seat.in");
	ofstream cout("seat.out");
	int a[15][15];
	int b[105];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>b[i];
	}
	int d=b[0];
	sort(b+0,b+0+n*m);
	int sum=0;
	for(int i=n*m-1;i>=0;i--)
	{
		sum++;
		if(b[i]==d)
		{
			break;
		}
	}
	
	int y=sum%n;
	int w;
	if(y==0)
	{
		w=sum/n;
		y=n;
	}
	else
	{
		w=sum/n+1;
	}
	if(w%2!=0)
	{
		cout<<w<<' '<<y;
	}
	else
	{
		cout<<w<<' '<<n-y+1;
	}
	return 0;
}

