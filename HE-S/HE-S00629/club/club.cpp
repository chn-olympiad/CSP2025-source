#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct s{
	int shu,p;
	s(int a,int b)
	{
		shu=a,p=b;
	}
};

bool operator<(const s&a,const s&b)//da
{
	return a.shu<b.shu;
}

int T;
int a[100009],b[100009],c[100009];//ºó¼õÈ¥Ç° 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		priority_queue<s>p;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n;
		cin>>n;
		int aa=0,bb=0,cc=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]<=b[i]&&a[i]<=c[i])
			{
				bb++,cc++;
				p.push(s(abs(c[i]-b[i]),i));
			}
			else if(b[i]<=a[i]&&b[i]<=c[i])
			{
				aa++,cc++;
				p.push(s(abs(c[i]-a[i]),i));
			}
			else if(c[i]<=b[i]&&c[i]<=a[i])
			{
				bb++,aa++;
				p.push(s(abs(b[i]-a[i]),i));
			}
		}
		
		ll ans=0,a1=0,b1=0,c1=0;
		while(!p.empty())
		{
			int y=p.top().p;
			p.pop();
			if(a[y]>=b[y]&&a[y]>=c[y])
			{
				if(a1<n/2)
				{
					a1++;
					ans+=a[y];
				}
				else
				{
					if(b[y]>=c[y])
					{
						b1++;
						ans+=b[y];
					}
					else
					{
						c1++;
						ans+=c[y];
					}
				}
			}
			else if(b[y]>=a[y]&&b[y]>=c[y])
			{
				if(b1<n/2)
				{
					b1++;
					ans+=b[y];
				}
				else
				{
					if(a[y]>=c[y])
					{
						a1++;
						ans+=a[y];
					}
					else
					{
						c1++;
						ans+=c[y];
					}
				}
			}
			else if(c[y]>=b[y]&&c[y]>=a[y])
			{
				if(c1<n/2)
				{
					c1++;
					ans+=c[y];
				}
				else
				{
					if(b[y]>=a[y])
					{
						b1++;
						ans+=b[y];
					}
					else
					{
						a1++;
						ans+=a[y];
					}
				}
			}
			
			
			
		}
	
		cout<<ans<<"\n";
		
	}
	
	
	
	return 0;
}


