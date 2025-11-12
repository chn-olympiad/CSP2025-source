#include<bits/stdc++.h>
using namespace std;
string s[100005],s2[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>s[i]>>s2[i];
	for (int i=1;i<=m;i++)
	{
		string t,tt;
		cin>>t>>tt;
		if (tt.size()!=t.size()) cout<<0<<endl;
		else 
		{
			long long ans=0;
			for (int j=1;j<=n;j++)
			{
				if (t.size()<s[j].size()) continue;
				for (int k=0;k<=t.size()-s[j].size();k++)
					if (t.substr(k,s[j].size())==s[j])
					{
						string x=t;
						x=t.substr(0,k)+s2[j]+t.substr(k+s[j].size(),t.size()-(k+s[j].size()));
						if (x==tt)
							ans++;
					}
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
