#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int c1[1101000],c2[1101000],w[1101000],gaizao[20],ww,b[1101000],s=1,wj,jw;
long long ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&c1[i],&c2[i],&w[i]);
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d",&gaizao[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&ww);
			c1[m+i*n+j]=n+i+1;
			c2[m+i*n+j]=j;
			w[m+i*n+j]=ww;
		}
	}
	w[0]=-101;
	m=m+k*n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(w[j]<w[j-1])
			{
				swap(w[j],w[j-1]);
				swap(c1[j],c1[j-1]);
				swap(c2[j],c2[j-1]);
			}
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		b[i]=i;
	}
	for(int i=1;i<=m && s<=n+k;i++)
	{
		if(b[c1[i]]==b[c2[i]])
		{
			continue;
		}
		s++;
		ans+=w[i];
		wj=min(b[c1[i]],b[c2[i]]);
		jw=max(b[c1[i]],b[c2[i]]);
		for(int i=1;i<=n+k;i++)
		{
			if(b[i]==wj)
			{
				b[i]=jw;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}