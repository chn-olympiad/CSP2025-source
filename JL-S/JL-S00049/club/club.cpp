#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,num1,num2,num3,sum;
struct cl{
	int num,a1,a2,a3,num0,d;
}a[maxn],b[maxn];
bool cmp(cl a,cl b)
{
	return a.d>b.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		num1=0;
		num2=0;
		num3=0;
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3) 
			{
				a[i].num=1;
				num1++;
				if(a[i].a2>=a[i].a3) 
				{
					a[i].num0=2;
					a[i].d=a[i].a1-a[i].a2;
				}
				else
				{
					a[i].num0=3;
					a[i].d=a[i].a1-a[i].a3;
				}
			}
			if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)
			{
				a[i].num=2;
				num2++;
				if(a[i].a1>=a[i].a3)
				{
					a[i].num0=1;
					a[i].d=a[i].a2-a[i].a1;
				}
				else
				{
					a[i].num0=3;
					a[i].d=a[i].a2-a[i].a3;
				}
			}
			if(a[i].a3>=a[i].a1&&a[i].a3>=a[i].a2)
			{
				a[i].num=3;
				num3++;
				if(a[i].a1>=a[i].a2) 
				{
					a[i].num0=1;
					a[i].d=a[i].a3-a[i].a1;
				}
				else 
				{
					a[i].num0=2;
					a[i].d=a[i].a3-a[i].a2;
				}
			}
		}
		if(num1<=n/2&&num2<=n/2&&num3<=n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].num==1) sum+=a[i].a1;
				if(a[i].num==2) sum+=a[i].a2;
				if(a[i].num==3) sum+=a[i].a3;
			}
			cout<<sum<<endl;
		}
		else
		{
			int c=1;
			//1
			if(num1>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i].num==1)
					{
						b[c].a1=a[i].a1;
						b[c].a2=a[i].a2;
						b[c].a3=a[i].a3;
						b[c].d=a[i].d;
						b[c].num=a[i].num;
						b[c].num0=a[i].num0;
						c++;
					}
					else 
					{
						if(a[i].num==1) sum+=a[i].a1;
						if(a[i].num==2) sum+=a[i].a2;
						if(a[i].num==3) sum+=a[i].a3;
					}
				}
				sort(b+1,b+c,cmp);
				for(int i=1;i<=n/2;i++)
				{
					if(b[i].num==1) sum+=b[i].a1;
					if(b[i].num==2) sum+=b[i].a2;
					if(b[i].num==3) sum+=b[i].a3;
				}
				for(int i=n/2+1;i<=c-1;i++)
				{
					if(b[i].num0==1) sum+=b[i].a1;
					if(b[i].num0==2) sum+=b[i].a2;
					if(b[i].num0==3) sum+=b[i].a3;
				}
				cout<<sum<<endl;
			}
			//2
			if(num2>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i].num==2)
					{
						b[c].a1=a[i].a1;
						b[c].a2=a[i].a2;
						b[c].a3=a[i].a3;
						b[c].d=a[i].d;
						b[c].num=a[i].num;
						b[c].num0=a[i].num0;
						c++;
					}
					else 
					{
						if(a[i].num==1) sum+=a[i].a1;
						if(a[i].num==2) sum+=a[i].a2;
						if(a[i].num==3) sum+=a[i].a3;
					}
				}
				sort(b+1,b+c,cmp);
				for(int i=1;i<=n/2;i++)
				{
					if(b[i].num==1) sum+=b[i].a1;
					if(b[i].num==2) sum+=b[i].a2;
					if(b[i].num==3) sum+=b[i].a3;
				}
				for(int i=n/2+1;i<=c-1;i++)
				{
					if(b[i].num0==1) sum+=b[i].a1;
					if(b[i].num0==2) sum+=b[i].a2;
					if(b[i].num0==3) sum+=b[i].a3;
				}
				cout<<sum<<endl;
			}
			//3
			if(num3>n/2)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i].num==3)
					{
						b[c].a1=a[i].a1;
						b[c].a2=a[i].a2;
						b[c].a3=a[i].a3;
						b[c].d=a[i].d;
						b[c].num=a[i].num;
						b[c].num0=a[i].num0;
						c++;
					}
					else 
					{
						if(a[i].num==1) sum+=a[i].a1;
						if(a[i].num==2) sum+=a[i].a2;
						if(a[i].num==3) sum+=a[i].a3;
					}
				}
				sort(b+1,b+c,cmp);
				for(int i=1;i<=n/2;i++)
				{
					if(b[i].num==1) sum+=b[i].a1;
					if(b[i].num==2) sum+=b[i].a2;
					if(b[i].num==3) sum+=b[i].a3;
				}
				for(int i=n/2+1;i<=c-1;i++)
				{
					if(b[i].num0==1) sum+=b[i].a1;
					if(b[i].num0==2) sum+=b[i].a2;
					if(b[i].num0==3) sum+=b[i].a3;
				}
				cout<<sum<<endl;
			}
			//over
		}
	}
	return 0;
}
