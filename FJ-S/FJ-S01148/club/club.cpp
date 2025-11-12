#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int ch[100005];
int cnt[3];
int t[100005],tot;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		tot=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int ma=0;
			for(int j=0;j<3;j++) if(a[i][j]>ma) ma=a[i][j],ch[i]=j;
			ans+=a[i][ch[i]],cnt[ch[i]]++;
		}
		int tmp=-1;
		for(int i=0;i<3;i++) if(cnt[i]>n/2) tmp=i;
		if(tmp==-1)
		{
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++) if(ch[i]==tmp)
		{
			t[++tot]=0;
			for(int j=0;j<3;j++) if(j!=tmp) t[tot]=max(t[tot],a[i][j]);
			t[tot]=a[i][tmp]-t[tot];
		}
		sort(t+1,t+1+tot);
		for(int i=1;i<=cnt[tmp]-n/2;i++) ans-=t[i];
		printf("%d\n",ans);
	}
	return 0;
}
