#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
void solve()
{
	string s1,s2; 
	int cnt=0;
	cin>>s1>>s2;
	int L=0,R=s1.size();
	int n=s1.size(),h=s2.size();
	for(;s1[L]==s2[L];L++);
	for(;s1[R]==s2[R];R--);
	for(int i=0;i<=L;i++)
		for(int j=n-1;j>=R;j--)
		{
			if(i+n-j-1+mp[s1.substr(i,j-i+1)].size()==h)
				if((s1.substr(0,i)+mp[s1.substr(i,j-i+1)]+s1.substr(j+1,n-j-1))==s2)
					++cnt;
		}
	cout<<cnt<<"\n";
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int ru,q;
	cin>>ru>>q;
	while(ru--)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--)
		solve();
	
	return 0;
}
