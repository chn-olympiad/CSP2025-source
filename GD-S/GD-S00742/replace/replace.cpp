#include <bits/stdc++.h>
using namespace std;
int n,q;
string x[2005],y[1005];
string m[1005],p[1005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i],m[i]=x[i],p[i]=y[i];
	while(q--)
	{
		int ans=0;
		string a,b;
		cin>>a>>b;
		string c[20005],d[20005];
		c[0]="";
		int len=a.size();
		for(int i=1;i<=len;i++) c[i]=c[i-1]+a[i-1];
		d[len+1]="";
		for(int i=len;i>=1;i--) d[i]=d[i+1]+a[i-1];
		for(int i=0;i<=len;i++)
		{
			for(int j=i+1;j<=len+1;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(c[i]+m[k]+d[j]==a&&c[i]+p[k]+d[j]==b) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
