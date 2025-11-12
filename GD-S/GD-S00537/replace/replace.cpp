#include <iostream>
#include <string>

using namespace std;

const int N=1005;

int n,q;

string s1[N],s2[N],t1,t2;
int bd1[N][N],bd2[N][N];

bool comp(int x)
{
	bool res=0;
	for(int i=0;i<t1.size();i++)
	{
		bool flg=1;
		for(int j=0;j<t1.size();j++)
		{
			if(s1[x].size()+i-1>=t1.size()) flg=0;
			
			if(j<i) flg=t1[j]==t2[j];
			if(0<=j-i&&j-i<s1[x].size()) flg=(t1[j]==s1[x][j-i])&&(t2[j]==s2[x][j-i]);
			if(j-i>=s1[x].size()) flg=t1[j]==t2[j];
			
			if(flg==0) break;
		}
		
		if(flg) return 1;
	}
	
	return 0;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	
	for(;q;q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		
		int res=0;
		for(int i=1;i<=n;i++) res+=comp(i);
		cout<<res<<"\n";
	}
	
	return 0;
}
