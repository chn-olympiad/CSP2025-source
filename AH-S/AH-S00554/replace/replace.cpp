#include<bits/stdc++.h>
using namespace std;

int n,q;
map <string,string> re;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--)
	{
		string a,b;
		cin>>a>>b;
		re[a]=b;
	}
	while(q--)
	{
		int ans=0;
		string a,b;
		cin>>a>>b;
		if(a.size()==b.size())
		{
			for(unsigned int i=0;i<a.size();i++)
			{
				string a1=a.substr(0,i+1),b1=b.substr(0,i+1);
				string a2=a.substr(i+1,a.size()-i-1),b2=b.substr(i+1,b.size()-i-1);
				if(re[a1]==b1&&a2==b2) ans++;
			}
			while(a[0]==b[0])
			{
				a.erase(0,1),b.erase(0,1);
				if(re[a]==b) ans++;
				string aa=a,bb=b;
				while(aa[aa.size()-1]==bb[bb.size()-1])
				{
					aa.erase(aa.size()-1,1),bb.erase(bb.size()-1,1);
					if(re[aa]==bb) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
