#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[100005][3];
int main()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	
	cin>>n;cin>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	
	while(q--)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			
			for(int j=0;j<t1.size()-s[i][1].size()+1;j++){
				bool st=1;
				for(int k=0;k<s[i][1].size();k++){
					if(s[i][1][k]!=t1[j+k])st=0;
				}
				if(st==0)continue;
				for(int k=0;k<j;k++){
					if(t2[k]!=t1[k])st=0;
				}
				for(int k=j;k<j+s[i][1].size();k++){
					if(t2[k]!=s[i][2][k-j])st=0;
				}
				for(int k=j+s[i][1].size();k<t2.size();k++){
					if(t2[k]!=t1[k])st=0;
				}
				if(st==0)continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
