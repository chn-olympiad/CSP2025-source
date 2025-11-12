#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct node{
	int id,va,t;
}f1[N],f2[N],f3[N];
int sum1=0,sum2=0,sum3=0;
int vis;
int t,n;
int a[N],b[N],c[N];
bool cmp(node a,node b)
{
	return a.va>b.va;
}
void sai()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=b[i]&&a[i]>=c[i])
		{
			f1[++sum1].id=i;f1[sum1].va=a[i]-max(b[i],c[i]);
//			if(b[i]>=c[i]) ?f1[sum1].t=2:f1[sum1].t=3;
			continue;
		}
		if(b[i]>a[i]&&b[i]>=c[i])
		{
			f2[++sum2].id=i;f2[sum2].va=b[i]-max(a[i],c[i]);
			continue;
		}
		f3[++sum3].id=i;f3[sum3].va=c[i]-max(a[i],b[i]);
	}
}
void work2()
{
	if(sum1>n/2)
	{
		sort(f1+1,f1+sum1+1,cmp);
		if(vis==2)
		{
			for(int i=sum1;i>=(n/2);i--)
			{
				f3[++sum3].id=f1[i].id;
				sum1--;
			}
		}
		else
		{
			for(int i=sum1;i>=(n/2);i--)
			{
				f2[++sum2].id=f1[i].id;
				sum1--;
			}
		}
		return;
	}
	if(sum2>n/2)
	{
		sort(f2+1,f2+sum2+1,cmp);
		if(vis==1)
		{
			for(int i=sum2;i>=(n/2);i--)
			{
				f3[++sum3].id=f2[i].id;
				sum2--;
			}
		}
		else
		{
			for(int i=sum2;i>=(n/2);i--)
			{
				f1[++sum1].id=f2[i].id;
				sum2--;
			}
		}
		return;
	}
	if(sum3>n/2)
	{
		sort(f3+1,f3+sum3+1,cmp);
		if(vis==2)
		{
			for(int i=sum3;i>=(n/2);i--)
			{
				f1[++sum1].id=f3[i].id;
				sum3--;
			}
		}
		else
		{
			for(int i=sum3;i>=(n/2);i--)
			{
				f2[++sum2].id=f3[i].id;
				sum3--;
			}
		}
		return;
	}
	return;
}
void work1()
{
	if(sum1>n/2)
	{
		vis=1;
		sort(f1+1,f1+sum1+1,cmp);
		for(int i=sum1;i>(n/2);i--)
		{
			if(b[f1[i].id]>=c[f1[i].id])
			{
				f2[++sum2].id=f1[i].id;
				f2[sum2].va=b[f1[i].id]-c[f1[i].id];
			}
			else
			{
				f3[++sum3].id=f1[i].id;
				f3[sum3].va=c[f1[i].id]-b[f1[i].id];
			}
			sum1--;
		}
		work2();
		return;
	}
	if(sum2>n/2)
	{
		vis=2;
//		cout<<"-";
		sort(f2+1,f2+sum2+1,cmp);
//		cout<<sum2<<" "<<n/2;
		for(int i=sum2;i>(n/2);i--)
		{
//			cout<<f2[i].id<<" ";
			if(a[f2[i].id]>=c[f2[i].id])
			{
				f1[++sum1].id=f2[i].id;
				f1[sum1].va=a[f2[i].id]-c[f2[i].id];
			}
			else
			{
				f3[++sum3].id=f2[i].id;
				f3[sum3].va=c[f2[i].id]-a[f2[i].id];
			}
			sum2--;
//			cout<<"+";
		}
//		cout<<"-"<<endl;
//		for(int i=1;i<=sum2;i++) cout<<f2[i].id<<" ";
//		cout<<endl;
		work2();
 		return;
	}
	if(sum3>n/2)
	{

		vis=3;
		sort(f3+1,f3+sum3+1,cmp);
		for(int i=sum3;i>(n/2);i--)
		{
			if(b[f3[i].id]>=a[f3[i].id])
			{
				f2[++sum2].id=f3[i].id;
				f2[sum2].va=b[f3[i].id]-a[f3[i].id];
			}
			else
			{
				f1[++sum1].id=f3[i].id;
				f1[sum1].va=a[f3[i].id]-b[f3[i].id];
			}
			sum3--;
		}
		work2();
		return;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		sum1=0;sum2=0;sum3=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		memset(f3,0,sizeof(f3));
		sai();
		work1();
		long long ans=0;
//		cout<<"/";
		for(int i=1;i<=sum1;i++)
		{
//			cout<<f1[i].id<<" ";
			ans+=a[f1[i].id];
		}
//		cout<<endl;
		for(int i=1;i<=sum2;i++)
		{
//			cout<<f2[i].id<<" ";
			ans+=b[f2[i].id];
		}
//		cout<<endl;
		for(int i=1;i<=sum3;i++)
		{
//			cout<<f3[i].id<<" ";
			ans+=c[f3[i].id];
		}
//		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
