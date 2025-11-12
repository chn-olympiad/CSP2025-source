#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,sum;
int len[200005];
string a[200005],b[200005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		len[i]=a[i].size();
	}
	while(q--)
	{
		sum=0;
		string s,e;
		cin>>s>>e;
		int lenn=s.size();
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=lenn-len[i];j++)
			{
				bool f=0;
				string z=s;
				for(int k=0;k<(int)a[i].size();k++)
				{
					if(a[i][k]!=s[j+k])
					{
						f=1;
						break;
					}
					z[j+k]=b[i][k];
				}
				if(!f)
				{
					if(z==e)
					{
						sum++;
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
*/
