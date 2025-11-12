#include<bits/stdc++.h>
using namespace std;
struct FSI
{
	template<typename T>
	FSI& operator >> (T &res)
	{
		res=0;T f=1;char ch=getchar();
		while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
		while(isdigit(ch)){res=res*10+(ch-'0');ch=getchar();}
		res*=f;
		return *this;
	}
}scan;
int T;
int n,a[100010][3];
int t[3],ans;
int b[3][100010];
void solve()
{
	scan>>n;
	for(int i=1;i<=n;i++) scan>>a[i][0]>>a[i][1]>>a[i][2];
	t[0]=t[1]=t[2]=0;ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]>=a[i][1]&&a[i][1]>=a[i][2])
		{
			b[0][++t[0]]=a[i][0]-a[i][1];
			ans+=a[i][0];
		}
		else if(a[i][0]>=a[i][2]&&a[i][2]>=a[i][1])
		{
			b[0][++t[0]]=a[i][0]-a[i][2];
			ans+=a[i][0];
		}
		else if(a[i][1]>=a[i][0]&&a[i][0]>=a[i][2])
		{
			b[1][++t[1]]=a[i][1]-a[i][0];
			ans+=a[i][1];
		}
		else if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][0])
		{
			b[1][++t[1]]=a[i][1]-a[i][2];
			ans+=a[i][1];
		}
		else if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][0])
		{
			b[2][++t[2]]=a[i][2]-a[i][1];
			ans+=a[i][2];
		}
		else if(a[i][2]>=a[i][0]&&a[i][0]>=a[i][1])
		{
			b[2][++t[2]]=a[i][2]-a[i][0];
			ans+=a[i][2];
		}
	}
	for(int i=0;i<=2;i++)
	{
		if(t[i]>n/2)
		{
			sort(b[i]+1,b[i]+t[i]+1);
			for(int j=1;j<=t[i]-n/2;j++) ans-=b[i][j];
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scan>>T;
	while(T--) solve();
	return 0;
}
