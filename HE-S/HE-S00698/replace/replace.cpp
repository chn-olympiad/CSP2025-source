#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int wa=1;wa<=q;wa++)
	{
		string a;
		string b;
		cin>>a>>b;
		int juq=0;
		for(int jj=1;jj<=n;jj++)
		{
			string s1=s[jj][1],s2=s[jj][2];
			int sum=0;
			if(a.size()==s1.size())
			{
				int f=0;
				if(a==s1&&b==s2) juq++;
				for(int i=0;i<a.size();i++)
				{
					if(a[i]==b[i]) f=0;
					if(a[i]!=b[i]&&f==1) continue;
					if(a[i]!=b[i])
					{
						if(a[i]==s1[i]&&b[i]==s2[i]) sum++;
						f=1;
					}
				}
			}
			if(sum==1) juq++;
		}
		cout<<juq<<endl;
	}
	return 0;
}
