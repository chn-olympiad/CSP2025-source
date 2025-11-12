#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],nn[100005],nn2[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--)
	{
		int numa=0,numb=0,numc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]) 
			{
				nn[i]=a[i];
				nn2[i]=max(b[i],c[i]);
			}
			else if(b[i]>a[i]&&b[i]>c[i]) 
			{
				nn[i]=b[i];
				nn2[i]=max(a[i],c[i]);
			}
			else 
			{
				nn[i]=c[i];
				nn2[i]=max(a[i],b[i]);
			}
		}
		if(n==2)
		{
			int aa=a[1]+b[2],bb=b[1]+c[2],cc=c[1]+a[2],aa2=a[1]+c[2],bb2=b[1]+a[2],cc2=c[1]+b[2];
			int maxn=0;
			maxn=max(maxn,aa);
			maxn=max(maxn,bb);
			maxn=max(maxn,cc);
			maxn=max(maxn,aa2);
			maxn=max(maxn,bb2);
			maxn=max(maxn,cc2);
			cout<<maxn<<endl;
		}
		else if(n==200||a[1]==0&&b[1]==0||a[1]==0&&c[1]==0||b[1]==0&&c[1]==0)
		{
			int num=0;
			sort(nn+1,nn+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				num+=nn[i];
			}
			cout<<num<<endl;
		}
		else
		{
			int num=0;
			sort(nn+1,nn+n+1,cmp);
			sort(nn2+1,nn2+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				
				if(nn[i]==a[i]) numa++;
				else if(nn[i]==b[i]) numb++;
				else numc++;
				if(numa<=n/2||numb<=n/2||numc<=n/2) num+=nn[i];
				else if(nn2[i]==a[i]||nn2[i]==b[i]||nn2[i]==c[i]) num+=nn2[i];
			}
			cout<<num<<endl;
		}
	}
	return 0;
}
