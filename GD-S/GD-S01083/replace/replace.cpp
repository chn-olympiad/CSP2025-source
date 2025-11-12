#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		string ss1,ss2;
		cin>>ss1>>ss2;
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			if(ss1==s1[i]&&ss2==s2[i])
			{
				flag=1;
				cout<<"1\n";
				break;
			}
		}
		if(flag==0)cout<<"0\n";
	}
	return 0;
}
