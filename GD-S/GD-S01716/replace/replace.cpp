#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,f,f1;
string ss,sss,s[100005],s1[100005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i]>>s1[i];
	if(n*m>10000000)
	{
		for(int i=1;i<=m;i++) cout<<0<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		cin>>ss>>sss;
		int q=ss.size()-1,t=sss.size()-1;
		for(int j=1;j<=n;j++)
		{
			int k=ss.find(s[j]),ff=0;
			if(k>=0&&k<=ss.size())
			{
				for(int l=0;l<k;l++) if(ss[l]!=sss[l]) ff=1;
				for(int l=k;l<=k+s[j].size()-1;l++) if(s1[j][l-k]!=sss[l]) ff=1;
				for(int l=k+s[j].size();l<=ss.size();l++) if(ss[l]!=sss[l]) ff=1;
				if(ff==0) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
