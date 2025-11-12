#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int n,t,a1[100005],a2[100005],a3[100005],p1,p2,p3,q1,q2,q3;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		int num=n/2,sum1=0,sum2=0,sum3=0;
		int maxn1=-1,maxn2=-1,maxn3=-1;
		for(int k=1;k<=n;k++)
		{
			for(int l=1;l<=n;l++)
			{
				if(maxn1<a1[l]&&q1<=num)
				{
					maxn1=a1[l];
					p1=l;
					q1++;
				}
				else if(maxn2<a2[l]&&q2<=num)
				{
					maxn2=a2[l];
					p2=l;
					q2++;
				}
				else if(maxn3<a3[l]&&q3<=num)
				{
					maxn3=a3[l];
					p3=l;
					q3++;
				}
		 	}
		 	if(maxn1!=-1)
		 	{
		 		sum1+=maxn1;	
			}
			if(maxn2!=-1)
		 	{
		 		sum2+=maxn2;	
			}
			if(maxn3!=-1)
		 	{
		 		sum3+=maxn3;	
			}
			a1[p1]=-1;
			a2[p2]=-1;
			a3[p3]=-1;
		}
		cout<<(sum1+sum2+sum3)<<endl;
	}
}
