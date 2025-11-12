#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,flag=0;
	string s1,s2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		string l="";
		int cnt=0;
		for(int i=0;i<s1.size();i++){
			string tmp="";
			for(int j=i;j<s1.size();j++){
				tmp+=s1[j];
				if(mp[tmp]!=""){
					string r="";
					for(int k=j+1;k<s1.size();k++) r+=s1[k];
					if(l+mp[tmp]+r==s2) cnt++;
				}
			}
			l+=s1[i];
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
