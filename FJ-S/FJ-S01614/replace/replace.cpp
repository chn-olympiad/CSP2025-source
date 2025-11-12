#include<bits/stdc++.h>
using namespace std;
int n,q;
string l[20005][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>l[i][1]>>l[i][2];
	while(q--)
	{
		string a,b;
		int ans=0;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			string xa=l[i][1]+"#"+a;
			int kmp[5005]={};
			for(int j=1;j<xa.size();j++)
			{
				if(xa[j]==xa[kmp[j-1]])
					kmp[j]=kmp[j-1]+1;
				else
				{
					int pos=j-1;
					while(pos>0)
					{
						pos=min(0,kmp[pos]-1);
						if(xa[j]==xa[pos])
						{
							kmp[j]=kmp[pos]+1;
							break;
						}
					}
				}
				if(kmp[j]==l[i][1].size())
				{
					string str1="";
					if(j-l[i][1].size()>0)
						str1+=a.substr(0,j-l[i][1].size()*2);
					str1+=l[i][2];
					if(a.size()-(j-l[i][1].size())>0)
						str1+=a.substr(j-l[i][1].size(),a.size()-(j-l[i][1].size()));
					if(str1==b)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
