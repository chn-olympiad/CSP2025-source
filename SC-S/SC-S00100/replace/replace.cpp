#include<bits/stdc++.h>
using namespace std;
int n,q;
map<pair<string,string>,vector<pair<string,string>>>m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int st=-1,en=-1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				if(st==-1){
					st=j;
				}
				en=j;
			}
		}
		if(st==-1)continue;
		string s3,s4,s5,s6;
		s5.clear(),s6.clear(),s3.clear(),s4.clear();
		for(int j=0;j<st;j++){
			s3=s3+s1[j];
		}
		for(int j=st;j<=en;j++){
			s4=s4+s1[j];
			s5=s5+s2[j];
		}
		for(int j=en+1;j<s1.size();j++){
			s6=s6+s1[j];
		}
		m[{s4,s5}].push_back({s3,s6});
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		int st=-1,en=-1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				if(st==-1){
					st=i;
				}
				en=i;
			}
		}
		string s4,s5;
		s4.clear(),s5.clear();
		for(int j=st;j<=en;j++){
			s4=s4+s1[j];
			s5=s5+s2[j];
		}
		int ans=0;
		for(auto j:m[{s4,s5}]){
			string s3=j.first,s6=j.second;
			int f=0;
			if(s3.size()>st)continue;
			if(s6.size()>s1.size()-en-1)continue;
			for(int l=1;l<=s3.size();l++){
				if(s1[st-l]!=s3[s3.size()-l]){
					f=1;
					break;
				}
			}
			if(f==1)continue;
			for(int l=0;l<s6.size();l++){
				if(s1[en+l+1]!=s6[l]){
					f=1;
					break;
				}
			}
			if(f==1)continue;
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}