//GZ-S00223 贵州省铜仁第一中学 李宜鸿
#include <bits/stdc++.h>
using namespace std;
int t,n;
int a1[100100],a2[100100],a3[100100];
int b1[100100],b2[100100],b3[100100];
int c[5];
int ans1[10];
int cnt;
int d1,d2,d3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int s=1;s<=t;s++)
	{
		cnt=0;
		d1=0;
		d2=0;
		d3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			c[1]=a1[i];
			c[2]=a2[i];
			c[3]=a3[i];
			sort(c+1,c+4);
			if(c[3]==a1[i])
			{
				d1++;
				b1[i]=c[3]-c[2];
			} 
			else if(c[3]==a2[i])
			{
				d2++;
				b2[i]=c[3]-c[2];
			}
			else 
			{
				d3++;
				b3[i]=c[3]-c[2];
			}
			cnt+=c[3];
		}
		sort(b1+1,b1+n+1);
		sort(b2+1,b2+n+1);
		sort(b3+1,b3+n+1);
		if(d1>n/2)
		{
			for(int i=1;i<=d1-n/2;i++)
			{
				cnt-=b1[i];
			}
		}
		else if(d2>n/2)
		{
			for(int i=1;i<=d2-n/2;i++)
			{
				cnt-=b2[i];
			}
		}
		else if(d3>n/2)
		{
			for(int i=1;i<=d3-n/2;i++)
			{
				cnt-=b1[i];
			}
		}
		ans1[s]=cnt;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans1[i]<<endl;
	}
	return 0;
} 

