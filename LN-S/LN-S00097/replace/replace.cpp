#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;
//woyaohaqi!
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	vector<string> y,y_;
	for(int i=0;i<n;i++)
	{
		string s;cin>>s;
		y.push_back(s);
		cin>>s;
		y_.push_back(s);
	}
	for(;m;m--)
	{
		int ans=0;
		string s,s_;
		cin>>s>>s_;
		
		for(int k=0;k<n;k++)
		{
			int i=0;
			while(i!=-1)
			{
				i=s.find(y[k],i);
				if(i==-1)break;
				string X,Z;
				for(int j=0;j<i;j++)
				{
					X.push_back(s[j]);
				}
				for(int j=i+y[k].size();j<s.size();j++)
				{
					Z.push_back(s[j]);
				}
				if(X+y_[k]+Z==s_)
					ans++;
				
				i++;
			}
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
