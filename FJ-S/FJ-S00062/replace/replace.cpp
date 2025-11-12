#include <iostream>
#include <cstring>
using namespace std;

string a[200005];
string b[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(q--)
	{
		string s,t;
		cin>>s>>t;
		int lens=s.length();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int lena=a[i].length();
			if(lens<lena)
			{
				continue;
			}
			for(int j=0;s[j+lena-1];j++)
			{
				if(s.substr(j,lena)!=a[i])
				{
					continue;
				}
				string temp=s;
				temp.replace(j,lena,b[i]);
				if(temp==t)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
