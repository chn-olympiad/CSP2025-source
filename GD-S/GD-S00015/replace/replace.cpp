#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q;
map<string,string> mp;
string sb[200005];
bool sub2=true;
ll as,bs2,bs1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
		sb[i]=s1;
		for(int i=0;i<s1.size();++i){
			if((s1[i]!='a'&&s1[i]!='b')||(s2[i]!='a'&&s2[i]!='b')){
				sub2=false;
			}
		}
		for(int i=0;i<s1.size();++i){
			if(s1[i]=='b'){
				bs1++;
			}
			if(s2[i]=='b'){
				bs2++;
			}
		}
		if(bs1!=1){
			sub2=false;
		}
		if(bs2!=1){
			sub2=false;
		}
	}
	
	if(q==1){
		ll ans=0;
		string l1,l2;
		cin>>l1>>l2;
		string ll1,ll2;
		ll1=l1,ll2=l2;
	    for(int i=1;i<=n;++i){
	    	for(int j=0;j+sb[i].size()-1<=ll1.size()-1;++j){
	    		if(ll1.substr(j,sb[i].size())==sb[i]){
	    			if(ll2.substr(j,mp[sb[i]].size())==mp[sb[i]]&&(ll1.substr(0,j)==ll2.substr(0,j))&&(ll1.substr(j+sb[i].size(),ll1.size()-j-sb[i].size()+1))==ll2.substr(j+sb[i].size(),ll1.size()-j-sb[i].size()+1)){
	    				
	    				ans++;
	    				break;;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	while(q--){
			ll ans=0;
			string l1,l2;
			cin>>l1>>l2;
			string ll1,ll2;
			ll1=l1,ll2=l2;
	    	for(int i=1;i<=n;++i){
	    		for(int j=0;j+sb[i].size()-1<=ll1.size()-1;++j){
	    			if(ll1.substr(j,sb[i].size())==sb[i]){
	    				if(ll2.substr(j,mp[sb[i]].size())==mp[sb[i]]&&(ll1.substr(0,j)==ll2.substr(0,j))&&(ll1.substr(j+sb[i].size(),ll1.size()-j-sb[i].size()+1))==ll2.substr(j+sb[i].size(),ll1.size()-j-sb[i].size()+1)){
	    				
	    				ans++;
	    				break;;
					}
					}
				}
			}
			cout<<ans<<"\n";
		}
		
		return 0;
	
	fclose(stdin);
	fclose(stdout);
	
} 
