#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[2][200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s1,s2;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[0][i]>>s[1][i];
	for(int i=1;i<=q;i++)
	{
		cin>>s1>>s2;
		if(s1==s2) cout<<n<<endl;
		else
			for(int j=1;j<=n;j++)
				for(int i=1;i<=j;i++)
					cout<<"nm";
	}
	return 0;
}
