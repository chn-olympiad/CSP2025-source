#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
string str1,str2;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>str1>>str2,mp[str1]=str2;
	while(m--){
		string s1,s2,ss1="",ss2="";
		int ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){puts("0");continue;}
		int be=0,ed=(int)s1.size()-1;
		for(int i=0;i<s1.size();i++)
			if(s1[i]!=s2[i]){
				be=i;
				break;
			}
		for(int i=s1.size()-1;i>=0;i--)
			if(s1[i]!=s2[i]){
				ed=i;
				break;
			}
		for(int i=be;i<=ed;i++) ss1=ss1+s1[i],ss2=ss2+s2[i];
		if(mp[ss1]==ss2) ans++;
		string sss1="",sss11="";
		for(int i=be-1;i>=0;i--){
			sss1=s1[i]+sss1;
			sss11=s2[i]+sss11;
			string sss2="",sss22="";
			for(int j=ed+1;j<s1.size();j++){
				sss2=sss2+s1[i];
				sss22=sss22+s2[i];
				if(mp[sss1+ss1+sss2]==sss11+ss2+sss22) ans++;
			}
				
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
