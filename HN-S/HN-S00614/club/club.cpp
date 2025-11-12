#include<bits/stdc++.h>
using namespace std;
bool cpp(int a,int b)
{
	return a>b;
}
struct zz{
	int k,f,z;
	int maxn;
};
bool cmp(zz a,zz b)
{
	return a.maxn>b.maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[100005],b[100005],c[100005],d[100005];
		cin>>n;
		int ans=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0) cnt2++;
			if(c[i]==0) cnt3++;
			d[i]=max(a[i],max(b[i],c[i]));
		}
		if(n==2)
		{
			
			if((d[1]==a[1]&&d[2]==a[2])||(d[1]==b[1]&&d[2]==b[2])||(d[1]==c[1]&&d[2]==c[2]))
			{
				if(d[1]<d[2])
				{
					ans+=d[2];
					if(d[1]==a[1])
					{
						ans+=max(b[1],c[1]);
					}
					else if(d[1]==b[1])
					{
						ans+=max(a[1],c[1]);
					}
					else if(d[1]==c[1])
					{
						ans+=max(a[1],b[1]);
					}
				}
				else if(d[1]>d[2])
				{
					ans+=d[1];
					if(d[2]==a[2])
					{
						ans+=max(b[2],c[2]);
					}
					else if(d[2]==b[2])
					{
						ans+=max(a[2],c[2]);
					}
					else if(d[2]==c[2])
					{
						ans+=max(a[2],b[2]);
					}
				}
				else if(d[1]==d[2])
				{
					ans+=d[1];
					if(d[1]==a[1]&&d[2]==a[2])
					{
						ans+=max(max(b[1],c[1]),max(b[2],c[2]));
					}
					else if(d[1]==b[1]&&d[2]==b[2])
					{
						ans+=max(max(a[1],c[1]),max(a[2],c[2]));;
					}
					else if(d[1]==c[1]&&d[2]==c[2])
					{
						ans+=max(max(b[1],a[1]),max(b[2],a[2]));
					}
				}
			}
			else
			{
				ans=d[1]+d[2];
			}
			cout<<ans;
		}
		else if(cnt2==n&&cnt3==n)
		{
			sort(a+1,a+n+1,cpp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i];
			}
			cout<<ans;
		}
		else if(cnt3==n)
		{
			zz l[10005];
			for(int i=1;i<=n;i++)
			{
				l[i].k=a[i];
				l[i].f=b[i];
				l[i].z=c[i];
				l[i].maxn=d[i];
			}
			sort(l+1,l+n+1,cmp);
			int fi=0,se=0;
			for(int i=1;i<=n;i++)
			{
				if(l[i].maxn==l[i].k&&fi<n/2)
				{
					fi++;
					ans+=l[i].k;
				}
				else if(l[i].maxn==l[i].f&&se<n/2)
				{
					se++;
					ans+=l[i].f;
				}
				else if(fi>=n/2)
				{
					se++;
					ans+=l[i].f;
				}
				else if(se>=n/2)
				{
					fi++;	
					ans+=l[i].k;
				}
			}
			cout<<ans;
		}
		else
		{
			zz l[10005];
			for(int i=1;i<=n;i++)
			{
				l[i].k=a[i];
				l[i].f=b[i];
				l[i].z=c[i];
				l[i].maxn=d[i];
			}
			sort(l+1,l+n+1,cmp);
			int fi=0,se=0,thr=0;
			for(int i=1;i<=n;i++)
			{
				if(l[i].maxn==l[i].k&&fi<=n/2)
				{
					fi++;
					ans+=l[i].k;
				}
				else if(l[i].maxn==l[i].f&&se<=n/2)
				{
					se++;
					ans+=l[i].f;
				}
				else if(l[i].maxn==l[i].z&&thr<=n/2)
				{
					se++;
					ans+=l[i].f;
				}
				else if(fi>=n/2)
				{
					int j=max(l[i].f,l[i].z);
					ans+=j;
					if(j==l[i].f&&se<n/2) se++;
					else thr++;
				}
				else if(se>=n/2)
				{
					int j=max(l[i].f,l[i].k);
					ans+=j;
					if(j==l[i].f&&se<n/2) se++;
					else fi++;
				}
				else if(thr>=n/2)
				{
					int j=max(l[i].k,l[i].f);
					ans+=j;
					if(j==l[i].f&&fi<n/2) fi++;
					else se++;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
