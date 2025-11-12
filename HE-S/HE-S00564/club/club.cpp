#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		vector<int> a1;
		vector<int> a2;
		vector<int> a3;
		cin>>n;
		int num1=0,num2=0,num3=0,q1,q2,q3;
		for(int j=0;j<n;j++)
		{
			cin>>q1;
			a1.push_back(q1);
			cin>>q2;
			a2.push_back(q2);
			cin>>q3;
			a3.push_back(q3);
		}
		vector<int> cho(n,0);
		int max=0,tmp=0;
		bool ch=true,ch1=true;
		while(ch)
		{
			for(int j=0;j<n;j++)
			{ 
				if(cho[j]==0)
				{
					tmp+=a1[j];
				}
				else if(cho[j]==1)
				{
					tmp+=a2[j];
				}
				else
				{
					tmp+=a3[j];
				}
			}
				if(tmp>=max)
				{
					max=tmp;
				}
		    tmp=0;
			for(int k=n-1;k>=0;k--)
			{
				if(cho[k]<2)
				{
					cho[k]++;
					if(cho[k]==2)
					{
						for(int l=n;l>k;l--)
						{
						    cho[l]=0;
						}
					}
					ch1=true;
					break;
				}
			}
			if(!ch1)
			{
				ch=false;
			}
			ch1=false;
		}
	cout<<max<<endl;
	}
	return 0;
}
