#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;

ll n,q;
string s1[N],s2[N],t1,t2;

vector<ll> v[27];

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		
		cin>>s1[i]>>s2[i];
		
		v[s1[i][0]-'a'].push_back(i);
	}
	
	while(q--){
		
		cin>>t1>>t2;
		
		if(t1.size()!=t2.size()){
			
			cout<<"0\n";
			continue;
		}
		
		ll ans=0;
		for(int i=0;i<t1.size();i++){
			
			for(auto id:v[t1[i]-'a']){
				
				if(s1[id].size()+i-1>=t1.size()) continue;
				
				ll op1=t1.find(s1[id],i);
				
				if(op1!=i) continue;
				
				string h=t1;
				h.replace(i,s2[id].size(),s2[id]);
				
				if(h==t2) ans++;
			}
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*

	ÄãËµµÃ¶Ô£¬µ«ÊÇ¹öÄ¾ÊÇÒ»¿îÓÉ¹öÄ¾¹öÄ¾µÄ¹öÄ¾¡£ÔÚ¹öÄ¾ÖÐ£¬¹öÄ¾Ðè¹öÄ¾¹öÄ¾£¬¹öÄ¾¹öÄ¾µÄ¹öÄ¾£¬¹öÄ¾¹öÄ¾¹öÄ¾¡£ 

*/
