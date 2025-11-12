#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,q,f,ans;
string a[200005],b[200005],s,t;
map<int,vector<pair<int,int>>> m;
inline bool check(string x)
{
	int l=x.size(),cnt1=0,cnt2=0;
	for(int i=0;i<l;i++)
		cnt1+=(x[i]=='a'),cnt2+=(x[i]=='b');
	return (cnt1==l-1&&cnt2==1);
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q,f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(f)
			f=check(a[i]);
		if(f)
			f=check(b[i]);
	}
	if(f)
	{
		for(int i=1;i<=n;i++)
		{
			int pp;
			for(int j=0;j<a[i].size();j++)
				if(a[i][j]=='b')
				{
					pp=j;
					break;
				}
			for(int j=0;j<b[i].size();j++)
				if(b[i][j]=='b')
				{
					m[pp-j].push_back({pp,a[i].size()-pp-1});
					break;
				}
		}
	}
	while(q--)
	{
		cin>>s>>t,ans=0;
		if(f&&check(s)&&check(t))
		{
			int pp,ppp;
			for(int j=0;j<s.size();j++)
				if(s[j]=='b')
				{
					pp=j;
					break;
				}
			for(int j=0;j<t.size();j++)
				if(t[j]=='b')
				{
					ppp=j;
					break;
				}
			int l=pp,r=s.size()-pp-1,xx=pp-ppp;
			for(int i=0;i<m[xx].size();i++)
				if(l>=m[xx][i].first&&r>=m[xx][i].second)
					ans++;
		}
		else{
			for(int i=1;i<=n;i++)
			{
				int l=a[i].size();
				for(int j=0;j+l-1<s.size();j++)
					if(s.substr(j,l)==a[i])
					{
						string xx=s;
						for(int k=j,kk=0;kk<l;kk++,k++)
							xx[k]=b[i][kk];
						ans+=(xx==t);
					}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
