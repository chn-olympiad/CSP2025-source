#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;

int n,q;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	vector<pair<string,string> > s;
	for(int i=0;i<n;i++)
	{
		string str1,str2;
		cin>>str1>>str2;
		s.push_back({str1,str2});
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			string str1=s[i].first,str2=s[i].second;
			int idx1=s1.find(str1),idx2=s2.find(str2);
			if(idx1==-1||idx2==-1) continue;
			if(idx1!=idx2) continue;
			string ss1=s1;
			for(int k=idx1;k<=idx1-1+str1.size();k++) ss1[k]=str2[k-idx1];
			if(ss1==s2) sum++;
//			cout<<ss1<<" "<<s2<<"+++\n";
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}
