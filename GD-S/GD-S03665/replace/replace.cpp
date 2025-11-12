#include<bits/stdc++.h>

using namespace std;

int n,q;
string s1[200007];
string s2[200007];
string t1[200007];
string t2[200007];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	
	while(q--){
		string t1,t2;
		set<pair<int,string>> ans;
		cin>>t1>>t2;
		
		for(int i=1;i<=n;i++){
			if(s1[i].size()>t1.size()) continue;
			
			for(int j=0;j<=t1.size()-s1[i].size();j++){
				bool flag=1;
				string ls=t1;
				for(int k=0;k<s1[i].size();k++){
					if(s1[i][k]!=t1[j+k]){
						flag=0;
						break;
					}else{
						ls[j+k]=s2[i][k];
					}
				}
				if(flag&&ls==t2) ans.insert({j,s2[i]});
			}
		}
		
		cout<<ans.size()<<endl;
	}
	
	return 0;
} 
