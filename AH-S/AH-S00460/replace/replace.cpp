#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
string q1,q2;
bool pd=false;
void solve()
{
	int ns,ne;
	int len=q1.size();
	for(int i=0;i<len;i++)
	{
		if(q1[i]!=q2[i]) 
			if(pd==false)
			{
				ns=i;
				break;
			}
	}
	for(int i=q1.size()-1;i>=0;i--)
	{
		if(q1[i]!=q2[i]) 
			if(pd==false)
			{
				ne=i;
				break;
			}
	}	
	string need1=q1.substr(ns,ne-ns+1),need2=q2.substr(ns,ne-ns+1);
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(q1.find(s[i][0])==string::npos) continue;
		int ks=q1.find(s[i][0]),ke=ks+s[i][0].size()-1;
		string k="";
		k+=q1.substr(0,ks);
		k+=s[i][1];
		k+=q1.substr(ke+1,q1.size()-1-ke);
		if(k==q2) count++;
	}
	cout<<count<<endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		cin>>q1>>q2;
		solve();
	}
	return 0;
}
