#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int n,q;
string replace(int st,int len,string s,string str){
	string s1=s.substr(0,st),s2=s.substr(st+len,s.size()-st-len+2);
	return s1+str+s2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(auto i:mp){
			string s1=i.first,s2=i.second;
			if(t1.size()-s1.size()+s2.size()!=t2.size())continue;
			int pos=0;
			while(t1.find(s1,pos)!=-1){
				int where=t1.find(s1,pos);
				int len=s1.size();
				string str=replace(where,len,t1,s2);
				if(str==t2){
					ans++;
				}
				pos=where+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//replace
