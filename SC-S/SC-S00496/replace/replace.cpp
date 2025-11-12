#include<bits/stdc++.h>
using namespace std;
string s1[200050],s2[200050];int n,q;
int main(){
	freeopen("replace.in","r",stdin);
	freeopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2,sh1="",sh2="";int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(t1.find(s1[i])!=t2.find(s2[i])){
				continue;
			}else{
				bool o=true;
				for(int j=t1.find(s1[i])+s1[i].size();j<t1.size();j++){
					if(t1[j]!=t2[j]){
						o=0;
						break;
					}
				}if(!o){
					continue;
				}
				for(int j=0;j<t1.find(s1[i]);j++){
					if(t1[j]!=t2[j]){
						o=0;
						break;
					}
				}if(!o){
					continue;
				}
				if(o){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}