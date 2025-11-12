#include<bits/stdc++.h>
using namespace std;
long long n,m;
map<string,map<string,int>> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2)continue;
		int l=0,r=s1.length()-1;
		while(s1[l]==s2[l])l++;
		while(s1[r]==s2[r])r--;
		s1=s1.substr(l,r-l+1),s2=s2.substr(l,r-l+1);
		mp[s1][s2]++;
	}
	for(long long i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<'\n';
			continue;
		}
		if(s1==s2)continue;
		int l=0,r=s1.length();
		while(s1[l]==s2[l])l++;
		while(s1[r]==s2[r])r--;
		s1=s1.substr(l,r-l+1),s2=s2.substr(l,r-l+1);
		cout<<mp[s1][s2]<<'\n';
	}
}
/*
l~r hash=hh[r]-hh[l-1]*pow(131,r-1+1)
*/
