#include<iostream>
using namespace std;
char dictionary[200005][2];
int len;
int main()
{
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>dictionary[i][1]>>dictionary[i][2];
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		len=s1.size();
		int ans=0;
		for(int i=1;i<=len;i++)
		{
			if(s1[i]!=s2[i])
			{
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
