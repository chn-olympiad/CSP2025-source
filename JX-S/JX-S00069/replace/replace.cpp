#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
map<string,string> mp;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		int cnt=0;
		for(map<string,string>::iterator it=mp.begin();it!=mp.end();it++){
			string str=it->first,rep=it->second;
			for(int i=0;i<s1.size();i++){
				string temp=s1;
				bool op=true;
				for(int j=0;j<str.size();j++){
					if(s1[i+j]!=str[j]){
						op=false;
						break;
					}
					temp[i+j]=rep[j];
				}
				if(!op)continue;
				if(temp==s2)cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
