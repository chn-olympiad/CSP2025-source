#include<bits/stdc++.h>
using namespace std;
string a[200001][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	while(q--)
	{
		string s,mb;
		cin>>s>>mb;\
		int cnt=0;
		int p=s.size();
		for(int i=1;i<=n;i++)
		{
			int len=a[i][1].size();
			string f=a[i][1];
			string b=a[i][2];
			for(int j=0;j<p-len+1;j++)
			{
				string ls=s;
				string qu=ls.substr(j,len);
				//cout<<qu<<"  ";
				if(qu==f)
				{
					ls.replace(j,len,b,0,b.size());
					//cout<<ls<<endl;
					if(ls==mb)
					{
						cnt++;
						//cout<<i<<" "<<j<<endl;
					}
				}
			}
			//cout<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
