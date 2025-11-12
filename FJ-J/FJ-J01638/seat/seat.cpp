#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll seat[100][100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	int test[1000];
	cin>>a>>b;
	for(int i=1;i<=a*b;i++)
	{
		cin>>test[i];
	}
	int r=test[1];
	sort(test+1,test+a*b+1);
	int tmp=a*b;
	for( int i=1;i<=b;i++)
	{
		int temp=0;
		for(int j=1;j<=a;j++)
		{
			if(i%2!=0)
			{
				seat[i][a-temp]=test[tmp];
			}
			if(i%2==0)
			{
				seat[i][j]=test[tmp];
			}
			temp+=1;
			tmp-=1;
		}
	}
	int l=0;
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(seat[i][j]==r)
			{
				for(int q=a;q>=j;q--)
				{
					l+=1;
				}
				cout<<i<<" "<<l<<endl;
				return 0;
			}
		}	
	}
	return 0;
}
