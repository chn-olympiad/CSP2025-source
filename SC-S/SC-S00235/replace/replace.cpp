#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,Q;cin>>n>>Q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(Q--){
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue; 
		}
		int ans=0;
		if(mp[t1]==t2)ans++;
		for(int i=0;i<t1.size();i++){
			for(int j=i+2;j<t1.size();j++){
				bool flag=0;
				for(int k=0;k<=i;k++){
					if(t1[k]!=t2[k]){
						flag=1;break;
					}
				}
				if(flag==1)continue;
				flag=0;
				for(int k=j;k<t1.size();k++){
					if(t1[k]!=t2[k]){
						flag=1;break;
					}
				}
				if(flag==1)continue;
				string x="",y="";
				for(int k=i+1;k<j;k++){
					x+=t1[k];y+=t2[k];
				}
				if(mp[x]==y)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 