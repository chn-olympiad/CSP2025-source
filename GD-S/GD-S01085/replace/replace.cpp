#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define M 1000010 
#define int long long
const int base = 131;
int n,q;
int po[M],a[N],b[N],c[M],d[M];
string x[N],y[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace4.in","r",stdin);
//	freopen("2.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	int len=0;
	for(int i=1;i<=n;i++)
	{
		len=max((int)x[i].size(),len);
		for(int j=0;j<x[i].size();j++) a[i]=a[i]*base+x[i][j]; 
		for(int j=0;j<y[i].size();j++) b[i]=b[i]*base+y[i][j];
	//	cout<<a[i]<<' '<<b[i]<<'\n';
	}
	po[0]=1;
	for(int i=1;i<=len;i++) po[i]=po[i-1]*base;
	string s,t;
	while(q--)
	{
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int e=0;
		c[0]=0;d[0]=0;
		for(int i=0;i<s.size();i++) c[i+1]=c[i]*base+s[i],d[i+1]=d[i]*base+t[i];
	//	cout<<c[s.size()]<<' '<<d[t.size()]<<'\n';
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int l=x[i].size();
			for(int j=0;j+l-1<s.size();j++)
			{
				int w1=c[j+l]-c[j]*po[l],w2=d[j+l]-d[j]*po[l];
				int e1=0,e2=0,e3=0,e4=0;
				if(j!=0) e1=c[j],e3=d[j];
				if(j+l!=s.size()) e2=c[s.size()]-c[j+l]*po[s.size()-j-l],e4=d[t.size()]-d[j+l]*po[t.size()-j-l];
				int q1=e1*po[s.size()-j]+b[i]*po[s.size()-j-l]+e2;
				int q2=e3*po[s.size()-j]+w2*po[s.size()-j-l]+e4;
				if(w1==a[i]&&w2==b[i])
				{
					if(q1==q2) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
 } 
 /*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


*/
