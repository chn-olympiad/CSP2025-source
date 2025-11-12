#include<bits/stdc++.h>
using namespace std;
bool days(int r,int c,int real)
{
	if(c==0)
	{
		return 0;
	}
	else if(real==0)
	{
		return 0;
	}
	else if(real==1)
	{
		return 1;
	}
} 
int main()
{
	freopen("std.in","r",stdin);
	freopen("std.out","w",stdout);
	int n,m,c[1001],pass=0,k=0,ways=0,temp=0,r[1001];
	int exam,s,real[1001];
	cin>>n;
	int day[1001];
	cin>>exam;
	if(exam==0||exam==1){
		s=exam;
	}	
	for(int i=1;i<+n;i++)
	{
		cin>>c[i];
	}
	int noreal=s;
	for(int i=1;i<+n;i++){
		real[i]=noreal%10;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			temp=r[i];
			r[i]=r[j];
			r[j]=temp;
			if(days(r[i],c[i],real[i]))
			{
				pass++;
			}
			else
			{
				c[i+1]--;
			}
		}
	}
	
	cout<<pass;
	return 0;
}
