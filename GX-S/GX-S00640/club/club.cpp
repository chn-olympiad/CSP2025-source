#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long t,n,c1,c2,c3,b1,b2,b3;
long long m[N],a[N],b[N],c[N],y[N],x;
void func(long long g,long long d,long long f)
{
	long long q;
	for(long long k=1;k<f;k++)
	{
		q=min(a[k]-y[k],q);
	}
		
}
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>n;
		x=n/2;
		for(long long j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			m[j]=max(a[j],b[j]);
			y[j]=min(m[j],c[j]);
			m[j]=max(m[j],c[j]);
		}
		for(long long j=1;j<=n;j++)
		{
			if(m[j]==a[j])
			{
				b1+=m[j];
				continue;
				//cout<<m[j]<<endl;
			}
			else if(m[j]==a[j])
			{
				b2+=m[j];
				continue;
				//cout<<m[j]<<endl;
			}
			else if(m[j]==a[j])
			{
				b3+=m[j];
				continue;
				//cout<<m[j]<<endl;
			}
		}
		cout<<b1+b2+b3<<endl;
		for(long long j=1;j<=n;j++)
		{
			//cout<<a[j]<<"!"<<endl;
		}
		for(int j=1;j<=n;j++)
		{
			m[j]=-1;
		}
	}
	return 0;
}
