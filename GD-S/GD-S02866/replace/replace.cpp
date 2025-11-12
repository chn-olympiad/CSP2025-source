#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,q;
string s1[N],s2[N],pre,rep;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans=0;
		cin>>pre>>rep;
		for(int z=1;z<=n;z++)
		{
			string ss1=pre,ss2=rep;
			int l1=ss1.size(),l2=s1[z].size();
			for(int i=0;i<l1-l2+1;i++)
				if(ss1[i]==s1[z][0]&&ss2[i]==s2[z][0])
				{
					int d=0;
					for(int j=0;j<l2;j++)
						if(ss1[i+j]!=s1[z][j]||ss2[i+j]!=s2[z][j]) 
						{
							d=1;
							break;
						}
						else ss1[i+j]=ss2[i+j];
					if(d==0&&ss1==ss2) 
					{
						ans++;
						break;
					}
					ss1=pre,ss2=rep;
				}		
		}
		cout<<ans<<"\n";
	}
	return 0;
}
