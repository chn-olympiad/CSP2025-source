#include<bits/stdc++.h>
using namespace std;
const int M = 2e5+5;
string s1[M],s2[M],t1,t2;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans = 0;
		cin>>t1>>t2;
		for(int i=0;i<n;i++)
			if(t1.size() >= s1[i].size())
			{
				string t = t1;
				int x = t.find(s1[i]);
				if(x == -1) break;
				for(int j=0;j<s1[i].size();j++)
					t[x+j] = s2[i][j];
				if(t == t2) ans++;
//				cout<<"\n"<<t+" "+t2+"\n";
			}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
