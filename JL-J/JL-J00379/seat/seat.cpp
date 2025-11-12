#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l;
	cin>>h>>l;
	int grades[l*h];
	int sets[h][l];
	int a1;
	for(int i=0;i<l*h;i++)
	{
		cin>>grades[i];
	}
	a1=grades[0];
	for(int i=0;i<l*h;i++)
	{
		for(int j=i+1;j<h*l;j++)
		{
			if(grades[j]>grades[i])
			{
				swap(grades[j],grades[i]);
			}
		}
	}
	int place=0;
	int gplace=0;
	for(int i=0;i<l;i++)
	{
		if(place==0)
		{
			for(;place<h;)
			{
				if(grades[gplace]==a1)
				{
					int a,b;
					a=i+1;
					b=place+1;
					cout<<a<<" "<<b;
					return 0;
				}
				sets[place][i]=grades[gplace];
				gplace++;
				place++;
			}
		}
		else if(place==h)
		{
			place--;
			for(;place>=0;)
			{
				if(grades[gplace]==a1)
				{
					int a,b;
					a=i+1;
					b=place+1;
					cout<<a<<" "<<b;
					return 0;
				}
				sets[place][i]=grades[gplace];
				gplace++;
				place--;
			}
			place++;
		}
	}
}

