#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N];
map<string,bool>mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		mp.clear();
		string st1,st2;
		cin>>st1>>st2;
		if(st1.size()!=st2.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=s1[i].size();
			if(l>st1.size()||mp[s1[i]])continue;
			for(int j=0;j<st1.size()-l+1;j++){
				if(st1.substr(j,l)!=s1[i])continue;
				if(st1.substr(0,j)+s2[i]+st1.substr(j+l,st1.size()-l-j)==st2)ans++;
				mp[s1[i]]=1;
			}
		}
		cout<<ans<<'\n';
	}
}
