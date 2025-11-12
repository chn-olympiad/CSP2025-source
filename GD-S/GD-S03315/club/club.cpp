#include<bits/stdc++.h>
#define ______ namespace
#define _______ std
using ______ _______;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		int n=read(),i,j,cnt[3]={0},ans=0;
		vector<int> a[3];
		for(int t=0;t<n;t++)
		{
			int b[3],mx=0;
			for(i=0;i<3;i++)
				b[i]=read(),mx=max(mx,b[i]);
			ans+=mx;
			for(i=0;i<3;i++)
				if(b[i]==mx)
				{
					int mx2=0;
					for(j=0;j<3;j++)
						if(i!=j)
							mx2=max(mx2,b[j]);
					a[i].push_back(mx-mx2);
					cnt[i]++;
					break;
				}
		}
		for(i=0;i<3;i++)
			if(cnt[i]>n/2)
			{
				sort(a[i].begin(),a[i].end());
				reverse(a[i].begin(),a[i].end());
				while(a[i].size()>n/2)
					ans-=a[i].back(),a[i].pop_back();
			}
		printf("%d\n",ans);
	}
}
