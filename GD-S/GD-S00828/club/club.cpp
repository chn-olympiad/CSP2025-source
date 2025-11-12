#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fe(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define fi first
#define se second
#define mk make_pair
const int N=1e5+5;
int n,d[N],T;
pair<int,int>a[N][3];
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=0;
		pair<int,int>s[3];
		fo(p,0,2) s[p]=mk(0,p);
		fo(i,1,n)
		{
			fo(p,0,2) a[i][p].fi=read(),a[i][p].se=p;
			sort(a[i],a[i]+2+1);
			ans+=a[i][2].fi,++s[a[i][2].se].fi;
		}
		sort(s,s+2+1);
		if(s[2].fi<=n/2)
		{
			printf("%d\n",ans);
			continue;
		}
		int cot=0;
		fo(i,1,n) if(a[i][2].se==s[2].se) d[++cot]=a[i][2].fi-a[i][1].fi;
		sort(d+1,d+cot+1);
		fo(i,1,s[2].fi-n/2) ans-=d[i];
		printf("%d\n",ans);
	} 
	return 0;
}
