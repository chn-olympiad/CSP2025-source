#include<bits/stdc++.h>
#include<math.h>
using namespace std;
string a;
int b;
long long int d;
int c=0;
long long int x[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<10;i++)
	{
		x[i]=0;
	}
	d=a.size();
	for(long long int i=0;i<d;i++)
	{
		b=a[i]-'0';
		if(b>=0&&b<=9)
		{
			x[b]=x[b]+1;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(x[i]!=0&&i!=0)
		{
			c=1;
		}
		if(c==1)
		{
			for(long long int j=1;j<=x[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}
