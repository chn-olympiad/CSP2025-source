#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int p[1000005];
struct xxs
{
	int l,r;
}q[1000005];
bool cmp(xxs x,xxs y)
{
	if(x.r!=y.r) return x.r<y.r;
	else if(x.r==y.r) return x.r-x.l<y.r-y.l;
	else return x.l<y.l;
}
long long ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	long long x,y,qz=1;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=a[i];
		y=p[i-1];
		s="";
		if(y==0) p[i]=x;
		else if(x==0) p[i]=y;
		else if(x==y) p[i]=0;
		else
		{
			while(x||y)
			{
				if(x%2==y%2) 
				{
					s+='0';
				}
				else
				{
					s+='1';
				}
				x/=2;
				y/=2;
			}
		}
		qz=1;
		for(int j=s.size()-1;j>=0;j--)
		{
			
			p[i]+=int(s[j]-'0')*qz;
			//cout<<p[i]<<endl;
			qz*=2;
			
		}
		//cout<<p[i]<<' ';
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				
				if(a[i]==k)
				{
					//cout<<i<<' '<<j<<endl;
					ans++;
					q[cnt].l=i;
					q[cnt].r=j;
					cnt++;
				}
			}
			else
			{
				if(i==1)
				{
					if(p[j]==k)
					{
						ans++;
						q[cnt].l=i;
						q[cnt].r=j;
						cnt++;
					}
				}
				else
				{
					x=p[j];
					y=p[i-1];
					s="";
					while(x||y)
					{
						if(x%2==y%2) 
						{
							s+='0';
						}
						else
						{
							s+='1';
						}
						x/=2;
						y/=2;
					}
					qz=1;
					int t=0;
					for(int k=s.size()-1;k>=0;k--)
					{
						
						t+=int(s[k]-'0')*qz;
						qz*=2;
						
					}
					t+=a[i];
					if(t==k)
					{
						ans++;
						q[cnt].l=i;
						q[cnt].r=j;
						cnt++;
					}
				}
			}
			
		}
	}
	sort(q,q+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		int sb=0;
		//cout<<q[i].l<<' '<<q[i].r<<endl;
		
		for(int j=i+1;j<cnt;j++)
		{
			if(q[i].r>=q[j].l)
			{
				sb++;
				ans--;
			}
			else break;
		}
		i+=sb;
		
	}
	cout<<ans;
	return 0;
}
