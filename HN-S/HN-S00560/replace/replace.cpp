#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,q,ans;
string s[N][2];
bool pan(string x,string y,int p)
{
	if(x.length()<p+y.length())
		return false;
	for(int i=p;i<=p+y.length()-1;++i)
		if(x[i]!=y[i-p])
			return false;
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<t1.length();++j)
			{
				if(!pan(t1,s[i][0],j))
					continue;
				for(int k=j;k<=j+s[i][0].length()-1;++k)
					t1[k]=s[i][1][k-j];
				if(t1==t2)
					++ans;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
