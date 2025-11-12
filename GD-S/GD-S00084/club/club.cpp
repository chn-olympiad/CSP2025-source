#include<bits/stdc++.h>
#define rd read()
#define int long long
using namespace std;
inline int read()
{
	int x=0,ss=1,s=getchar();
	while((s<'0'||s>'9')&&s!='-')s=getchar();
	if(s=='-')ss=-1,s=getchar();
	while(s>='0'&&s<='9')x=x*10+s-'0',s=getchar();
	return x*ss;
}
const int N=100005;
int n,ans,a[5][N];
vector<int> v[5];
inline bool cmp1(int x,int y){return a[1][x]-max(a[2][x],a[3][x])<a[1][y]-max(a[2][y],a[3][y]);}
inline bool cmp2(int x,int y){return a[2][x]-max(a[1][x],a[3][x])<a[2][y]-max(a[1][y],a[3][y]);}
inline bool cmp3(int x,int y){return a[3][x]-max(a[1][x],a[2][x])<a[3][y]-max(a[1][y],a[2][y]);}
inline void sol()
{
	v[1].clear(),v[2].clear(),v[3].clear();
	n=rd;int d=n/2;ans=0;
	for(int i=1;i<=n;++i)a[1][i]=rd,a[2][i]=rd,a[3][i]=rd;
	for(int i=1;i<=n;++i)
		if(a[1][i]>a[2][i]&&a[1][i]>a[3][i])v[1].push_back(i),ans+=a[1][i];
		else if(a[2][i]>a[3][i])v[2].push_back(i),ans+=a[2][i];
		else v[3].push_back(i),ans+=a[3][i];
	sort(v[1].begin(),v[1].end(),cmp1);
	sort(v[2].begin(),v[2].end(),cmp2);
	sort(v[3].begin(),v[3].end(),cmp3);
	int siz=v[1].size(),p=0,P;while(siz>d)P=v[1][p],--siz,++p,ans-=a[1][P]-max(a[2][P],a[3][P]);
	siz=v[2].size(),p=0;while(siz>d)P=v[2][p],--siz,++p,ans-=a[2][P]-max(a[1][P],a[3][P]);
	siz=v[3].size(),p=0;while(siz>d)P=v[3][p],--siz,++p,ans-=a[3][P]-max(a[1][P],a[2][P]);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	int T;cin>>T;while(T--)sol();return 0;
}
