#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	int const stu=n*m;
	int score[stu];
	for(int i=0;i<n*m;i++)
	{
		cin>>score[i];
		if(i==0)
		{
			R=score[i];
		}
	}
	
	int min=200;
	for(int i=0;i<n*m;i++)
	{
		if(score[i]<=min)
		{
			min=score[i];
		}
	}
	int sc[stu];
	for(int i=0;i<n*m;i++)
	{
		sc[n*m-(i+1)]=min;
		min=200;
		for(int j=0;j<n*m;j++)
		{
			if(min>=score[j]&&score[j]>sc[n*m-i-1])
			{
				min=score[j];
			}
		}
	}
	
	for(int i=0;i<n*m;i++)
	{
		if(sc[i]==R)
		{
			float b;
			int l;
			b=(i+1)*1.0/n;
			if(b-((i+1)/n)!=0)
			{
				l=((i+1)/n)+1;
			}
			else
			{
				l=(i+1)/n;
			}
			if(l%2==0)
			{
				cout<<l<<" "<<n-((i+1)%n)+1;
				break;
			}
			else
			{
				cout<<l<<" ";
				if((i+1)%n==0)
				{
					cout<<n;
				}
				else
				{
					cout<<(i+1)%n;
				}
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
