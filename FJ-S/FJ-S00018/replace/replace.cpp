#include<bits/stdc++.h>
using namespace std;
string s[200];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n*2;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<q;i++)
	{
		map<char,int>m;
		string a,b;
		cin>>a>>b;
		for(int j=0;j<(int)a.size();j++)
		{
			m[a[j]]++;
		}
		int cnt=0;
		for(int j=0;j<(int)b.size();j++)
		{
			if(m[b[j]]==0)
			{
				cnt++;
			}
		}
		if(cnt==(int)b.size())
		{
			cout<<0<<endl;
			continue;
		}
		else
		cout<<2<<endl;
	}
	return 0;
}
