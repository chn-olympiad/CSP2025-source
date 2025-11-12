#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10,N=2e6+10;
ll n,q,a1[maxn],a2[maxn],num[N],num_end[N];
struct node
{
	int a,g,en,id;
}b[maxn];
string s1[maxn],s2[maxn],t1,t2;
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a<y.a;
	return x.g<y.g;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++)
		{
			if(s1[i][j]=='b')
			{
				a1[i]=j;break;
			}
		}
		for(int j=0;j<s2[i].size();j++)
		{
			if(s2[i][j]=='b')
			{
				a2[i]=j;break;
			}
		}
	}
	if(n<=100&&q<=100)
	{
		while(q--)
		{
			cin>>t1>>t2;
			ll ans=0;
			if(t1.size()==t2.size())
			{
				for(int i=1;i<=n;i++)
				{
					if(s1[i].size()<=t1.size())
					{
						for(int j=0;j<t1.size()-s1[i].size()+1;j++)
						{
							bool o2=0;
							for(int k=0;k<s1[i].size();k++)
							{
								if(s1[i][k]!=t1[j+k]||s2[i][k]!=t2[j+k])
								{
									o2=1;break;
								}
							}
							if(o2==0) 
							{
								for(int k=0;k<j;k++) 
									if(t1[k]!=t2[k]) 
									{
										o2=1;break;
									}
								if(o2==0)
									for(int k=j+s1[i].size();k<t1.size();k++)
										if(t1[k]!=t2[k]) 
										{
											o2=1;break;
										}	
								if(o2==0) ans++;								
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++) 
	{
		b[i].id=i;b[i].a=a1[i]-a2[i];b[i].g=a1[i];b[i].en=s1[i].size();
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n+1;i++)
	{
		if(b[i].a!=b[i-1].a||i==1) num[b[i].a]=i,num_end[b[i-1].a]=i-1;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<" "<<s1[b[i].id]<<" "<<s2[b[i].id]<<" "<<b[i].a<<endl;
//	}
//	for(int i=-4;i<=4;i++)
//	{
//		cout<<i<<" "<<num[i]<<" "<<num_end[i]<<endl;
//	}
	ll op=0;
	while(q--)
	{
		op++;
		cin>>t1>>t2;
		int num1,num2;
		for(int i=0;i<t1.size();i++) 
		{
			if(t1[i]=='b')
			{
				num1=i;break;
			}
		}
		for(int i=0;i<t2.size();i++)
		{
			if(t2[i]=='b')
			{
				num2=i;break;
			}
		}
		ll ans=0;
		if(t1.size()==t2.size())
			for(int i=num[num1-num2];i<=num_end[num1-num2];i++)
			{
				if(num_end[num1-num2]==0) break;
				if(b[i].en-b[i].g<=t1.size()-num1&&b[i].g<=num1)
				{
//					cout<<i<<endl;
					ans++;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
