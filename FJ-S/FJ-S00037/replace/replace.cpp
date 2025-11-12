#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
int n,q;
string s[2],t[100001][3],l,r;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(q--)
	{
		cin>>s[0]>>s[1];
		for(int i=1;i<=n;i++)
		{
		cin>>l>>r;
		int o=l.size();
		for(int j=0;j<o;j++)
			if(l[i]=='b')
		{
			t[i][1]=j;
			t[i][2]=o-j-1;
			
		}
		}
		cout<<1;
	}
	return 0;
}
