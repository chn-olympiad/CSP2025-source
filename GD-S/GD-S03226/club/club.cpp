#include<bits/stdc++.h>
using namespace std;
struct maxjz{
	int maxi,max1,max2;
}m[100001];
int t,n,a[4],maxc[4];
bool cmp(maxjz A,maxjz B)
{
	if(A.max2!=B.max2)
	return A.max2>B.max2;
	else
	return A.max1<B.max1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(m,0,sizeof(m));
		memset(maxc,0,sizeof(maxc));
		long long ans=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[1]>>a[2]>>a[3];
			if(max(a[1],max(a[2],a[3]))==a[1])
			{
			maxc[1]++;
			m[j].maxi=1;
			}
			if(max(a[1],max(a[2],a[3]))==a[2])
			{
			maxc[2]++;
			m[j].maxi=2;
			}
			if(max(a[1],max(a[2],a[3]))==a[3])
			{
			maxc[3]++;
			m[j].maxi=3;
			}
			sort(a+1,a+4);
			m[j].max1=a[3];
			m[j].max2=a[2];
		}
		sort(m+1,m+1+n,cmp);
		if(maxc[1]<=n/2&&maxc[2]<=n/2&&maxc[3]<=n/2)
		{
		for(int j=1;j<=n;j++)
		ans+=m[j].max1;
		cout<<ans<<endl;
		continue;
		}
		else
		{
			int jl=0;
			if(max(maxc[1],max(maxc[2],maxc[3]))==maxc[1])
			jl=1;
			if(max(maxc[1],max(maxc[2],maxc[3]))==maxc[2])
			jl=2;
			if(max(maxc[1],max(maxc[2],maxc[3]))==maxc[3])
			jl=3;
			for(int j=1;j<=n;j++)
			{
				if(m[j].max1==m[j].max2)
					maxc[jl]--;
			}
		if(maxc[1]<=n/2&&maxc[2]<=n/2&&maxc[3]<=n/2)
		{
		for(int j=1;j<=n;j++)
		ans+=m[j].max1;
		cout<<ans<<endl;
		continue;
		}
		else
		{
			for(int j=1;j<=n;j++)
			if(m[j].maxi!=jl)
			{
				ans+=m[j].max1;
				m[j].max1=-1;
			}
			int ne=maxc[jl]-n/2;
			for(int j=1,k=1;j<=ne;k++)
			if(m[k].max1!=-1)
			{
			ans+=m[k].max2;
			m[k].max1=-1;
			j++;
			}
			for(int j=1;j<=n;j++)
			if(m[j].max1!=-1)
			ans+=m[j].max1;
		}
		cout<<ans<<endl;
		}
	}
	return 0;
}
