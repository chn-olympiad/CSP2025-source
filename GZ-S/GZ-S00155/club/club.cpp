//GSP-S00155 遵义市播州区新蓝学校 张幕寒
#include <bits/stdc++.h>
using namespace std;
int n,t,i,tn[6],j,sum;
struct stu
{
	int sn;
	int s1;
	int s2;
	int s3;
	int zhu;
};
stu a[6][10010];
void d1(stu b[],int k)
{
	for(int mm=0;mm<tn[k];mm++)
		for(int x=1;x<tn[k];x++)
		{
			if(b[x].s1>b[x+1].s1)
				swap(b[x],b[x+1]);	
		}
	int s=tn[k]/2,ok=1;
	for(int x=1;x<=s;x++)
	{
		ok=1;
		if(b[x].zhu!=0)
		{
			s++;
			ok=0;
		}
		if(ok)
		{
			a[k][x].zhu=1;
		}
	}
			
} 
void d2(stu b[],int k)
{
	for(int mm=0;mm<tn[k];mm++)
		for(int x=1;x<tn[k];x++)
		{
			if(b[x].s2>b[x+1].s2)
				swap(b[x],b[x+1]);	
		}
	int s=tn[k]/2,ok=1;
	for(int x=1;x<=s;x++)
	{
		ok=1;
		if(b[x].zhu!=0)
		{
			s++;
			ok=0;
		}
		if(ok)
		{
			a[k][x].zhu=2;
		}
	}
			
} 
void d3(stu b[],int k)
{
	for(int mm=0;mm<tn[k];mm++)
		for(int x=1;x<tn[k];x++)
		{
			if(b[x].s3>b[x+1].s3)
				swap(b[x],b[x+1]);	
		}
	int s=tn[k]/2,ok=1;
	for(int x=1;x<=s;x++)
	{
		ok=1;
		if(b[x].zhu!=0)
		{
			s++;
			ok=0;
		}
		if(ok)
		{
			a[k][x].zhu=3;
		}
	}
			
} 
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		tn[i]=n;
		sum=0;
		for(j=1;j<=n;j++)
		{	
			a[i][j].sn=j;
			cin>>a[i][j].s1;
			cin>>a[i][j].s2;
			cin>>a[i][j].s3;
		}	
		d1(a[i],i);	
		d2(a[i],i);
		d3(a[i],i);
		for(j=1;j<=n;j++)
		{
			if(a[i][j].zhu==1)
			{
				sum+=a[i][j].s1;
			}
			if(a[i][j].zhu==2)
			{
				sum+=a[i][j].s2;
			}
			if(a[i][j].zhu==3)
			{
				sum+=a[i][j].s3;
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

