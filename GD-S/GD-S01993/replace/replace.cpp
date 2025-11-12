#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> PSS;
int n,q;
const int maxn=2e5,maxq=2e5;
string S[maxn+5][3],T[maxq+5][3];
vector<PSS> end_with[26];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	{
		cin>>S[i][1]>>S[i][2];
		end_with[S[i][1][S[i][1].size()-1]-'a'].push_back({S[i][1],S[i][2]});
	}
	for (int i=1;i<=q;i++)
	{
		cin>>T[i][1]>>T[i][2];
		int len=T[i][1].size(),cnt=0;
		if (T[i][2].size()!=len)
		{
			cout<<0<<endl;
			continue;
		}
		for (int j=0;j<len;j++)
		{
			for (auto choose:end_with[T[i][1][j]-'a'])
			{
				int replace_len=choose.first.size();
				if (j+1>=replace_len)
				{
					string changed=T[i][1].substr(0,j+1-replace_len)+choose.second+T[i][1].substr(j+1);
					if (changed==T[i][2]) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
 } 
