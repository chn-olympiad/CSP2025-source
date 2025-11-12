#include<bits/stdc++.h>
using namespace std;
struct l
{
	long long a,b,c,z,f=0,d;
}h[100005];
bool cmp(l x,l y)
{
	return 2*x.z-x.d>y.z*2-y.d;
}
long long t,n,ans=0,k,q=0;
char dd;
queue <long long> ka,bk,kc;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		
		t--;
		cin>>n;
		q=0;
		k=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>h[i].a>>h[i].b>>h[i].c;
			
			h[i].z=max(h[i].a,max(h[i].b,h[i].c));
			h[i].d=h[i].a+h[i].b+h[i].c-h[i].z;
		}
		sort(h+1,h+n+1,cmp);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(h[i].a>h[i].b&&h[i].a>h[i].c)
			{
				if(ka.size()+1<=k)
				{
					
					ka.push(h[i].a);
				}
				else
				{
					q=i;
					dd='a';
					break;
				}
			}
			else if(h[i].b>h[i].a&&h[i].b>h[i].c)
			{
				if(bk.size()+1<=k)
				{
					bk.push(h[i].b);
				}
				else
				{
					q=i;
					dd='b';
					break;
				}
			}
			else if(h[i].c>h[i].b&&h[i].c>h[i].a)
			{
				if(kc.size()+1<=k)
				{
					kc.push(h[i].c);
				}
				else
				{
					q=i;
					dd='c';
					break;
				}
			}
			else
			{
				ans+=max(h[i].a,max(h[i].b,h[i].c));
			}
		}
		if(q!=0)
		{
			
			if(dd=='a')
			{
				for(int i=q;i<=n;i++)
				{
					ans+=max(h[i].b,h[i].c);
				}
				
			}
			if(dd=='b')
			{
				for(int i=q;i<=n;i++)
				{
					ans+=max(h[i].a,h[i].c);
				}
				
			}
			if(dd=='c')
			{
				for(int i=q;i<=n;i++)
				{
					ans+=max(h[i].b,h[i].a);
				}
				
			}
		}
		
		while(kc.size()||bk.size()||ka.size())
		{
			if(kc.size())
			{
				ans+=kc.front();
				kc.pop();
			}
			if(ka.size())
			{
				ans+=ka.front();
				ka.pop();
			}
			if(bk.size())
			{
				ans+=bk.front();
				bk.pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
