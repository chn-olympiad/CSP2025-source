#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
int a[100001],b[100001],c[100001];
vector<int> cl[4];
int rd()
{
	int asn=0;char ch=getchar();
	while('0'>ch||'9'<ch)ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		asn=(asn<<3)+(asn<<1)+(ch-'0');
		ch=getchar();
	}
	return asn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd();
	while(T--)
	{
		ans=0;cl[1].clear();cl[2].clear();cl[3].clear();
		n=rd();
		for(int i=1;i<=n;i++)a[i]=rd(),b[i]=rd(),c[i]=rd();
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i]&&a[i]>c[i])
			{
				cl[1].push_back(a[i]-max(b[i],c[i]));
				ans+=a[i];
			}
			else if(b[i]>=a[i]&&b[i]>c[i])
			{
				cl[2].push_back(b[i]-max(a[i],c[i]));
				ans+=b[i];
			}
			else
			{
				cl[3].push_back(c[i]-max(a[i],b[i]));
				ans+=c[i]; 
			}
		}
		for(int i=1;i<=3;i++)
		{
			int len=cl[i].size();
			if(len>n/2)
			{
				sort(cl[i].begin(),cl[i].end());
				for(int j=0;j<len-n/2;j++)ans-=cl[i][j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
