#include <bits/stdc++.h>
using namespace std;
int Q,n,ans;
string s1[200005],s2[200005];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(Q--)
	{
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=t1.size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s1[j].size()<=t1.size()-i+1 && s1[j].size()<=t2.size()-i+1){
				    if(t1.substr(i,s1[j].size()+i)==s1[j] && t2.substr(i,s2[j].size()+i)==s2[j] && t1.substr(1,i-1)==t2.substr(1,i-1) && t1.substr(s1[j].size()+i+1,t1.size())==t2.substr(s2[j].size()+i+1,t2.size())){
					    ans++;
				    }
			    }
			}
		}
		if(t1.size()!=t2.size())
		{
			cout<<0<<'\n';
		}
		else cout<<ans<<'\n';
	 } 
	return 0;
}
