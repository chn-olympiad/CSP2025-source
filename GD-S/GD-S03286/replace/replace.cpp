#include<bits/stdc++.h>

using namespace std;

int n,q,ans,len;
string s1,s2,st1,st2;
set<string>s;
map<string,string>mp;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		s.insert(s1),mp[s1]=s2;
	}
	while(q--){
		cin>>s1>>s2;
		len=s1.size(),ans=0;
		for(int i=0;i<len;i++){
			for(int j=i;j<len;j++){
				for(int k=i;k<=j;k++) st1+=s1[k],st2+=s2[k];
				if(s.count(st1) && mp[st1]==st2){
					ans++;
				}
				st1.clear(),st2.clear();
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

