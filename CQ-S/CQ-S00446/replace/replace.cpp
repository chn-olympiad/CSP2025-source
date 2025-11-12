#include <bits/stdc++.h>
using namespace std;
const int TOP=2e5+5;
int st;
int n/*谐音个数*/,m/*问题个数*/;
string a[TOP],b[TOP];
string t1,t2;
int ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(m--)
	{
		ans=0;
		cin>>t1>>t2;
		st=t1.size();
		for(i=1;i<=n;i++)
		{
			int sa=a[i].size();
			for(j=0;j<=st-sa;j++)
			{
				bool yes=true;
				for(k=j;k<j+sa;k++)
				{
					if(a[i][k-j]==t1[k])
						continue;
					yes=false;
					break;
				}
				if(!yes)
					continue;
				for(k=j;k<j+sa;k++)
					t1[k]=b[i][k-j];
				if(t1==t2)
					ans++;
				for(k=j;k<j+sa;k++)
					t1[k]=a[i][k-j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
