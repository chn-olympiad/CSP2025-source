#include<bits/stdc++.h>
using namespace std;
struct node
{
	int b[5],f,s;
}a[100005],tmp[100005];
int t,c[5],idx=0;
bool cmp(node x,node y)
{
	return x.b[x.f]-x.b[x.s]>y.b[y.f]-y.b[y.s]; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
			int x=a[i].b[1],y=a[i].b[2],z=a[i].b[3];
			if(x>y&&x>z)
			{
				a[i].f=1;
				if(y>z) a[i].s=2;
				else a[i].s=3;
			}
			else if(y>z)
			{
				a[i].f=2;
				if(x>z) a[i].s=1;
				else a[i].s=3;
			}
			else
			{
				a[i].f=3;
				if(x>y) a[i].s=1;
				else a[i].s=2;
			}
		}
		long long sum=0;
		for(int i=1;i<=n;i++) c[a[i].f]++;
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2)
			for(int i=1;i<=n;i++) sum+=a[i].b[a[i].f];
		else
		{
			int s=0;
			if(c[1]<=n/2)
			{
				for(int i=1;i<=n;i++)
					if(a[i].f==1) sum+=a[i].b[a[i].f];
			}
			else s=1;
			if(c[2]<=n/2)
			{
				for(int i=1;i<=n;i++)
					if(a[i].f==2) sum+=a[i].b[a[i].f];
			}
			else s=2;
			if(c[3]<=n/2)
			{
				for(int i=1;i<=n;i++)
					if(a[i].f==3) sum+=a[i].b[a[i].f];
			}
			else s=3;
			for(int i=1;i<=n;i++)
				if(a[i].f==s) tmp[++idx]=a[i];
			sort(tmp+1,tmp+idx+1,cmp);
			for(int i=1;i<=n/2;i++) sum+=tmp[i].b[tmp[i].f];
			for(int i=n/2+1;i<=idx;i++) sum+=tmp[i].b[tmp[i].s];
			memset(tmp,0,sizeof tmp);
			idx=0;
		}
		cout<<sum<<endl;
	}
	return 0;
}

