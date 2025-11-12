#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q,len1,len2,ans;
vector<int> v[N];
char a[N],b[N];
int pos1,pos2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		len1=strlen(a);
		for(int i=0;i<len1;i++)
		{
			if(a[i]=='b')
			{
				pos1=i;
				break;
			}
		}
		for(int i=0;i<len1;i++)
		{
			if(b[i]=='b')
			{
				pos2=i;
				break;
			}
		}
		v[abs(pos2-pos1)].push_back(len1);
	}
	while(q--)
	{
		cin>>a>>b;
		len1=strlen(a);
		len2=strlen(b);
		if(len1!=len2)
		{
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<len1;i++)
		{
			if(a[i]=='b')
			{
				pos1=i;
				break;
			}
		}
		for(int i=0;i<len1;i++)
		{
			if(b[i]=='b')
			{
				pos2=i;
				break;
			}
		}
		ans=0;
		for(int i=0;i<v[abs(pos1-pos2)].size();i++) if(v[abs(pos1-pos2)][i]<=len1) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}