#include<bits/stdc++.h>
using namespace std;
int t,n,a[114514][5],b[114514],maxn[114514],cmaxn[114514],maxi[114514],cmaxi[114514],ans,mn,mi;
struct st
{
	int cc,num;
}c[114514];
bool cmp(st xx,st yy)
{
	return xx.cc<yy.cc;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	scanf("%d",&t);
	while(t--)
	{
		int s[5]={0,0,0,0,0},mn=0,mi=0;
		memset(c,0,sizeof(c));
		memset(maxn,0,sizeof(maxn));
		memset(cmaxn,0,sizeof(cmaxn));
		memset(maxi,0,sizeof(maxi));
		memset(cmaxi,0,sizeof(cmaxi));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(maxn[i]<a[i][j]) cmaxn[i]=maxn[i],cmaxi[i]=maxi[i],maxn[i]=a[i][j],maxi[i]=j;
				else if(cmaxn[i]<a[i][j]) cmaxn[i]=a[i][j],cmaxi[i]=j;
			}
			ans+=maxn[i],s[maxi[i]]++;
			c[i].cc=maxn[i]-cmaxn[i],c[i].num=i;
			if(s[maxi[i]]>mn) mn=s[maxi[i]],mi=maxi[i];
		}
		sort(c+1,c+1+n,cmp);
		int p=1;
		while(s[mi]>n/2)
		{
			if(maxi[c[p].num]==mi)
			{
				s[mi]--,s[cmaxi[c[p].num]]++,ans-=c[p].cc;
				p++;
			}
			else p++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
