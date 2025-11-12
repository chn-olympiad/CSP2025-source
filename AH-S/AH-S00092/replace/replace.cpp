#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=31;
int n,q,pw[200100];
vector<int> h[200100][3],h1,h2;
string s[200100][3],a1,a2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=200000;++i)pw[i]=pw[i-1]*p;
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=n;++i)
	{
		h[i][1].push_back(0);
		int lst=0;
		for(int j=0;j<s[i][1].size();++j)
		{
			h[i][1].push_back(lst*p+s[i][1][j]-'a');
		}
		
		h[i][2].push_back(0);
		lst=0;
		for(int j=0;j<s[i][2].size();++j)
		{
			h[i][2].push_back(lst*p+s[i][2][j]-'a');
		}
	}
	for(int i=1;i<=q;++i)
	{
		cin>>a1>>a2;
		if(a1.size()!=a2.size())
		{
			cout<<"0\n";
			continue;
		}
		h1.clear();h2.clear();
		h1.push_back(0);
		int lst=0;
		for(int j=0;j<a1.size();++j)
		{
			h1.push_back(lst*p+a1[j]-'a');
		}
		h2.push_back(0);
		for(int j=0;j<a2.size();++j)
		{
			h2.push_back(lst*p+a2[j]-'a');
		}
		int l=INT_MAX,r=0;
		for(int j=1;j<=a1.size();++j)
		{
			if(a1[j-1]!=a2[j-1])l=min(j,l),r=max(j,r);
		}
		if(l==INT_MAX)l=0,r=0;
		//l++,r++;
		int ans=0,d=r-l+1;
		//printf("%lld %lld\n",l,r);
		if(l!=0&&r!=0)
		{
			for(int k=1;k<=n;++k)
			{
				if(s[k][1].size()<d)continue;
				for(int g=1;g+d-1<=s[k][1].size();++g)
				{
					int st=l-g+1;
					if(st+s[k][1].size()-1>n)continue;
					//printf("%lld %lld %lld\n",k,st,st+s[k][1].size()-1);
					//if((h[k][1][g+d]-h[k][1][g-1])*pw[l-1]==(h1[r]-h1[l-1])*pw[g-1]&&)
					if(h1[st+s[k][1].size()-1]-h1[st-1]==h[k][1][s[k][1].size()-1]*pw[st-1]&&h2[st+s[k][1].size()-1]-h2[st-1]==h[k][2][s[k][1].size()-1]*pw[st-1])ans++;
				}
			}
		}
		else
		{
			for(int j=1;j<=n;++j)
			{
				for(int k=1;k<=a1.size()&&k+s[j][1].size()-1<=n;++k)
				{
					if(h1[k+s[j][1].size()-1]-h1[k-1]==h[j][1][s[j][1].size()]*pw[k-1]&&h2[k+s[j][1].size()-1]-h2[k-1]==h[j][2][s[j][1].size()]*pw[k-1])ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
