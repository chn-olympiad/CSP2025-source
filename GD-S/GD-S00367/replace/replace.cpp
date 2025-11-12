#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m;
string s1[N],s2[N],t1[N],t2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		cin>>t1[i]>>t2[i];
		for(int j=1;j<=n;j++)
		{
			int u=t1[i].find(s1[j]);
			if(u!=-1) 
			{
				string h=t1[i];
				for(int k=u,l=0;k<=u+s1[j].size()-1;k++,l++)
					h[k]=s2[j][l];
				if(h==t2[i]) ans++; 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
