#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],a,b;
int n,q;
long long ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[1]>>s2[i];
	while(q--)
	{
		cin>>a>>b;
		for(int i=1;i<=n;i++) 
		{
			bool qq=0;
			for(int j=0;j+s1[i].size()-1<a.size();j++)
			{
				for(int l=0;l<s1[i].size();l++)
				{
					if(s1[i][l]!=a[l+j]||s2[i][l]!=b[l+j])
					{
						qq=1;
						break;
					}
				}
				if(qq) break;
			}
			if(!qq) ans++;
		}
		cout<<ans;
	}
	return 0;
}
