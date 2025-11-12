#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2e5+100;
pair<string,string> s[MAXN];
int n,q;
int main()
{
	FILE* fp;
	fp=freopen("replace.in","r",stdin);
	fp=freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i].first>>s[i].second;
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		int cnt=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++)
		{
			string tmp=t1;
			int lasp=0;
			while(1)
			{
				//cerr<<tmp.substr(lasp,tmp.size()-lasp)<<'\n';
				int pos=tmp.substr(lasp,tmp.size()-lasp).find(s[j].first);
				lasp+=pos;
				if(pos==-1) break;
				for(int k=0;k<(int)s[j].first.size();k++)
					tmp[lasp+k]=s[j].second[k];
				if(tmp==t2)
					cnt++;
				lasp++;
				tmp=t1;
			}
			
		}
		cout<<cnt<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}