#include<bits/stdc++.h>
using namespace std;
int t;
long long n,q1,q2,q3,s,c;
long long a1[200001],a2[200001],a3[200001];
long long b1[100001],b2[100001],b3[100001];
int cmp1(int x,int y)
{
	return x<y;
}
int cmp2(int x,int y)
{
	return x<y;
}
int cmp3(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		s=0;
		q1=0,q2=0,q3=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a1[i],&a2[i],&a3[i]);
			if(a1[i]>=a2[i]&&a1[i]>=a3[i])
			{
				q1++;
				s+=a1[i];//s统计最大数和 
				b1[q1]=a1[i]-max(a2[i],a3[i]);
				//b数组代表最大数与第二数的差 
			}
			else if(a2[i]>a1[i]&&a2[i]>=a3[i])
			{
				q2++;
				s+=a2[i];
				b2[q2]=a2[i]-max(a1[i],a3[i]);
				
			}
			else if(a3[i]>a2[i]&&a3[i]>a1[i])
			{
				q3++;
				s+=a3[i];
				b3[q3]=a3[i]-max(a2[i],a1[i]);
			}
		}
		if(q1<=n/2&&q2<=n/2&&q3<=n/2)
		{
			cout<<s<<"\n";
			continue;
		}
		if(q1>n/2)
		{
			sort(b1+1,b1+q1,cmp1);
			c=q1-n/2;
			for(int i=1;i<=c;i++)
			{
				s-=b1[i];//距一半差几个减几个 
			}
			cout<<s<<"\n";
			
		}
		else if(q2>n/2)
		{
			sort(b2+1,b2+q2,cmp2);
			c=q2-n/2;
			for(int i=1;i<=c;i++)
			{
				s-=b2[i];
			}
			cout<<s<<"\n";
		}
		else if(q3>n/2)
		{	
			sort(b3+1,b3+q3,cmp3);
			c=q3-n/2;
			for(int i=1;i<=c;i++)
			{
				s-=b3[i];
			}
			cout<<s<<"\n";
		}
	}
	return 0;
}//<-91=78+13 编译时间：0.91s 
