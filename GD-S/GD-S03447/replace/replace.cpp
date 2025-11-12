#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,vector<pair<pair<string,string>,pair<string,string> > > > s;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int k=1;k<=n;k++){
		string s1,s2;
		cin>>s1>>s2;
		int i=0,j=s1.size()-1;
		while(i<=j&&s1[i]==s2[i])
			i++;
		if(i>j)
			continue;
		while(j>=0&&s1[j]==s2[j])
			j--;
		string now1=s1.substr(i,j-i+1),now2=s2.substr(i,j-i+1);
		s[make_pair(now1,now2)].push_back(make_pair(make_pair(s1.substr(0,i),s1.substr(j+1,s1.size()-j-1)),make_pair(s2.substr(0,i),s2.substr(j+1,s2.size()-j-1))));
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<"\n";
			continue;
		}
		int i=0,j=s1.size()-1;
		while(i<=j&&s1[i]==s2[i])
			i++;
		if(i>j)
			continue;
		while(j>=0&&s1[j]==s2[j])
			j--;
		string now1=s1.substr(i,j-i+1),now2=s2.substr(i,j-i+1);
//		cout<<now1<<","<<now2<<"\n";
		int siz=s[make_pair(now1,now2)].size(),ans=0;
		for(int k=0;k<siz;k++){
			pair<pair<string,string>,pair<string,string> > now_s=s[make_pair(now1,now2)][k];
			if(now_s.first.first.size()>i||now_s.first.second.size()>s1.size()-j-1)
				continue;
			ans+=(now_s==make_pair(make_pair(s1.substr(i-now_s.first.first.size(),now_s.first.first.size()),s1.substr(j+1,now_s.first.second.size())),make_pair(s2.substr(i-now_s.second.first.size(),now_s.second.first.size()),s2.substr(j+1,now_s.second.second.size()))));
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
