#include<bits/stdc++.h>

using namespace std;

int t,n,n2;

struct man{
	int a1,a2,a3;
	int b,c;
}a[100005];

bool cmp(man x,man y)
{
	if(x.b==y.b)
	{
		return max(x.a1,x.a2)>max(y.a1,y.a2);
	}
	return x.b>y.b;
}

void chu()
{
	for(int i=1;i<=n;i++)
	{
		a[i].a1=0;
		a[i].a2=0;
		a[i].a3=0;
		
	}
	return;
}

int sea(int x,int u1,int u2,int u3)
{
	if(u1>n2||u2>n2||u3>n2)
	{
		return -100000;
	}
	if(x>n)
	{
		return 0;
	}
	int s1=sea(x+1,u1+1,u2,u3)+a[x].a1;
	int s2=sea(x+1,u1,u2+1,u3)+a[x].a2;
	int s3=sea(x+1,u1,u2,u3+1)+a[x].a3;
	return max(s1,max(s2,s3));
} 

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;	
		chu();
		n2=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		
		if(n>=30)
		{
			for(int i=1;i<=n;i++)
			{
				a[i].b=max(a[i].a1,a[i].a2)-min(a[i].a1,a[i].a2);
				if(a[i].a1>=a[i].a2)
				{
					a[i].c=1;
				}
				else
				{
					a[i].c=2;
				}
			}
			sort(a+1,a+1+n,cmp);
			int u1=0,u2=0;
			long long sum=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].c==1&&u1<=n2)
				{
					sum+=a[i].a1;
					u1++;
					continue;
				}
				if(a[i].c==2&&u2>n2)
				{
					sum+=a[i].a1;
					u1++;
					continue;
				}
				sum+=a[i].a2;
				u2++;
			}
			cout<<sum<<endl;
		}
		if(n<30)
		{	
			//cout<<"1"<<endl;
			cout<<sea(1,0,0,0)<<endl;

		}
	}
	return 0;
}
