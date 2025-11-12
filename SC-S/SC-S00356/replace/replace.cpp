#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e6+5;
int n,q;
pair<string,string>a[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	IOS;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second;
	while(q--)
	{
		long long ans=0;
		string s,t;
		cin>>s>>t;
		for(int i=0;i<s.length();i++)
		{
			for(int p=1;p<=n;p++)
			{
				string pre,sub,nxt,t1=a[p].first,t2=a[p].second;
				if(i+t1.length()-1>=s.length()) continue;
				if(i==0) pre="";
				else pre=s.substr(0,i+1);
				sub=s.substr(i,t1.length());
				if(sub!=t1) continue;
				sub=t2;
				if(i+t1.length()-1==s.length()-1) nxt="";
				else nxt=(i+t1.length(),s.length()-i-t1.length());
				if(t==pre+sub+nxt) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}