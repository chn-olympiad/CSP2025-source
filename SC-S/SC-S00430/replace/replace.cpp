#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>

const int N=5e6+5,fac=1331,mod=998244353;
int n,q;
string t1[N],t2[N];
string s1,s2;
int tot1=0,tot2=0;
unordered_map<int,int> mp;
unordered_map<int,vector<pii>> mp2;
int hsh[N];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	if(n<=100){
		for(int i=1;i<=n;i++) cin>>t1[i]>>t2[i];
		for(int i=1;i<=q;i++){
			cin>>s1>>s2;int len=s1.size();s1=' '+s1,s2=' '+s2;
			int cnt=0;
			for(int j=1;j<=n;j++){
				string p=" ";
				for(int k=1;k<=len;k++){
					if(s1.substr(k,t1[j].size())==t1[j]){
						p=p+t2[j];
						while(p.size()<s1.size()) p+=s1[p.size()];
						if(p!=s2){
							break;
						}
						else cnt++;
					}
					p+=s1[k];
				}
			}
			cout<<cnt<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;int len=s1.size();
		s1=' '+s1,s2=' '+s2;
		int L=1,R=len;
		while(s1[L]==s2[L]) L++;
		while(s1[R]==s2[R]) R--;
		int h1=0,h2=0;
		for(int j=L;j<=R;j++){
			h1*=fac;
			(h1+=s1[j]-'a'+1)%=mod;
			h2*=fac;
			(h2+=s2[j]-'a'+1)%=mod;
		}
		if(!mp[h1*mod+h2*131]) mp[h1*mod+h2*131]=++tot1;
		int nw=mp[h1*mod+h2*131];
		int h3=0;
		for(int j=L-1;j>=1;j--){
			h3*=fac;
			(h3+=s1[j]-'a')%=mod;
		}
		int h4=0;
		for(int j=R+1;j<=len;j++){
			h4*=fac;
			(h4+=s1[j]-'a')%=mod;
		}
		mp2[h3*mod+nw*131].push_back({len-R,h4});
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		int len=s1.size();
		s1=' '+s1,s2=' '+s2;
		int L=1,R=len;
		while(s1[L]==s2[L]) L++;
		while(s1[R]==s2[R]) R--;
		int h1=0,h2=0;
		for(int j=L;j<=R;j++){
			h1*=fac;
			(h1+=s1[j]-'a'+1)%=mod;
			h2*=fac;
			(h2+=s2[j]-'a'+1)%=mod;
		}
		if(!mp[h1*mod+h2*131]){
			cout<<0<<endl;
			continue;
		}
		int nw=mp[h1*mod+h2*131];
		int h4=0;
		hsh[0]=0;
		for(int j=R+1;j<=len;j++){
			h4*=fac;
			(h4+=s1[j]-'a')%=mod;
			hsh[j-R]=h4;
		}
		int h3=0,ans=0;
		for(int j=L-1;j>=1;j--){
			h3*=fac;
			(h3+=s1[j]-'a')%=mod;
			for(pii k:mp2[h3*mod+nw*131]){
				if(hsh[k.first]==k.second) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//rp++
//唉，死了