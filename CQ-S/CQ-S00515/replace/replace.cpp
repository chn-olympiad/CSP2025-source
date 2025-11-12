#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define fi first
#define sd second
#define pb push_back
#define mk make_pair
#define endl '\n'
namespace wilbur
{
	const int N=2050;
	int n,q;
	string s[N],t[N];
	int len[N];
	int main()
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i]>>t[i];
			len[i]=s[i].size();
		}
		for(int i=1;i<=q;i++)
		{
			string a,b;
			cin>>a>>b;
			int x=a.size(),ans=0,pos=0;
			for(int j=x-1;j>=0;j--)
			{
				if(a[j]!=b[j])
				{
					pos=j;
					break;
				}
			}
			for(int j=0;j<x;j++)
			{
				if(j>0)
					if(a[j-1]!=b[j-1])break;
				for(int k=1;k<=n;k++)
				{
//					if(j==2)cout<<k<<" "<<len[k]<<" "<<j+len[k]-1<<" "<<pos<<" "<<x<<endl;
					if(j+len[k]-1>=x)continue;
					if(pos>j+len[k]-1)continue;
					bool flag=true;
					for(int l=j;l<=j+len[k]-1;l++)if(a[l]!=s[k][l-j])
					{
						flag=false;
						break;
					}
					if(!flag)continue;
					for(int l=j;l<=j+len[k]-1;l++)if(b[l]!=t[k][l-j])
					{
						flag=false;
						break;
					}
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	wilbur::main();
	return 0;
}

