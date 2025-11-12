#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define reg register 
const ll N=200010;


ll n,q,chgcnt[N],cntt,stt,edd,ans;
bool f,fb;
string s1[N],s2[N],t1,t2; 

ll s1b,s2b,dx[N];



inline ll cntdiff(string s1,string s2){
	ll ans=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]) ans++;
	}
	return ans;
}

inline string substr(string s,ll id,ll len){
	string ans="";
	for(int i=id,j=0;j<len;j++) ans+=s[i+j];
	return ans;
}
int main(){
	ios::sync_with_stdio(false);

	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		
		
		chgcnt[i]=cntdiff(s1[i],s2[i]);
	}
//	if(fb==false){
//		for(int i=1;i<=q;i++){
//			cin>>t1>>t2;
//			
//		}
//	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		f=true;
		ans=cntt=0;
		for(reg int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				cntt++;
				if(f){
					stt=j;
					f=0;
				}
				edd=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(s1[j].size()>t1.size()||chgcnt[j]!=cntt||s1[j].size()<edd-stt+1) continue;
			ll tmp=s1[j].size()-(edd-stt+1)+1;
			for(int id=0;id<tmp;id++){
				if(stt-tmp+id+1<0||edd+id>=t1.size()) continue;
				if(edd+id>=t1.size()) break;
				if(substr(t1,stt-tmp+id+1,s1[j].size())==s1[j]&&substr(t2,stt-tmp+id+1,s2[j].size())==s2[j]){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
} 
