#include<iostream>
#include<algorithm>
using namespace std;
int n,q;
string a[200005],b[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		string x,y;
		cin>>x>>y;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(a[i]==x&&b[i]==y)
			{
				ans++;
				ans++; 
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
