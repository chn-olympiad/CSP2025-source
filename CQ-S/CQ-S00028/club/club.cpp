#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int T;
int n;
int a[100005][4];
vector<int>bel[4];
int tmp[100005],cnt;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=3;i++) bel[i].clear();
		for(int i=1;i<=n;i++)
		{
			int p=0;a[i][0]=-1;
			for(int j=1;j<=3;j++) 
			{
				a[i][j]=read();
				if(a[i][j]>a[i][p]) p=j;
			}
			bel[p].push_back(i);
		}
		int mx=0;
		for(int i=1;i<=3;i++) if(bel[i].size()>bel[mx].size()) mx=i;
		int ans=0;
		if(bel[mx].size()<=n/2)
		{
			for(int i=1;i<=3;i++)
				for(int j:bel[i]) ans+=a[j][i];
		}
		else
		{
			cnt=0;
			for(int i=1;i<=3;i++)
				for(int j:bel[i]) ans+=a[j][i];
			for(int i:bel[mx]) 
			{
				int w=0;
				for(int j=1;j<=3;j++) if(j!=mx) w=max(w,a[i][j]);
				tmp[++cnt]=-a[i][mx]+w;
			}
			sort(tmp+1,tmp+cnt+1);
			for(int i=1;i<=bel[mx].size()-n/2;i++) ans+=tmp[cnt-i+1];
		}
		write(ans),putchar('\n');
	}
	return 0;
}

