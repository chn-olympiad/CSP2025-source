#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int s,d,f;
		int mx1=0,mx2=0,mx3=0;
		queue<int> q1;
		queue<int> q2;
		queue<int> q3;
		int sum1=0,sum2=0,sum3=0;
		for(int j=1;j<=n;j++)
		{
			cin>>s>>d>>f;
			if(s>d&&s>f)
			{
				if(q1.size()<n/2)
				{
					q1.push(1);
					sum1+=s;
				} 
			}
			if(d>s&&d>f)
			{
				if(q2.size()<n/2)
				{
					q2.push(d);
					sum2+=d;
				} 
			}
			if(f>d&&f>s)
			{
				if(q3.size()<n/2)
				{
					q3.push(f);
					sum3+=f;
				} 				
			}
		}
		cout<<sum1+sum2+sum3;
	}
}
 
