#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=2e5+5;
string s1[N],s2[N],t1[N],t2[N];
int ans=0;
bool op1,op2;
string a,b,c,d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
	}
	for(int x=1;x<=q;x++)
	{
		ans=0;
		for(int i=0;i<t1[x].size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				int l=s1[j].size();
				string c=t1[x].substr(i,l);
				
				if(c==s1[j]&&l+i<=t1[x].size()&&l+i<=t2[x].size())
				{
					a=t1[x].substr(0,i);
				b=t1[x].substr(i+l,t1[x].size()-l-i);
				string no=a+s2[j]+b;
				//cout<<no<<endl;
				if(no==t2[x])
				{
					ans++;
				}
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
