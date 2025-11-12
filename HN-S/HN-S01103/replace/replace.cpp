#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//string s[N],s2[N];
unordered_map <string,string> s;
unordered_map <string,string> s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string k,g;
		cin>>k>>g;
		s[k]=k;
		s2[g]=g;
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2,ns1="",ns2="";
		cin>>t1>>t2;
		//cout<<t1<<" "<<t2<<endl;
		int sz=t1.size();
		int ans=0,cnt=0;
		for(int i=0;i<sz;i++)
		{
			if(t1[i]!=t2[i])
			{
				cnt++;
			}
		}
		for(int i=0;i<sz;i++)
		{
			for(int j=1;j<sz-i+1;j++)
			{
				string now1=t1.substr(i,j),now2=t2.substr(i,j);
				if(s[now1]!=""&&s2[now2]!=""&&s[now1].size()>=cnt)
				{
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
