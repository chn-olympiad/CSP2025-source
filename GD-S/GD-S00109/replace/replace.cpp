#include<bits/stdc++.h>
using namespace std;
int n,q,f,l,cnt,ans,sum,nx;
string s1,s2,noww,noww2,t1,t2;
vector<pair<string,string> > vec[200005];
map<string,int> mp;
bool fi(string a,string b){
	if(a.find(b)>=a.size()){
		return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		sum+=s1.size();
		cin>>s1>>s2;
		if(s1==s2){
			vec[0].push_back({s1,s2});
			continue;
		}
		f=0;
		while(s1[f]==s2[f]){
			f++;
		}
		l=s1.size()-1;
		while(s1[l]==s2[l]){
			l--;
		}
		noww="";
		noww2="";
		for(int j=f;j<=l;j++){
			noww=noww+s1[j];
			noww2=noww2+s2[j];
		}
		noww=noww+noww2;
		if(mp[noww]==0){
			cnt++;
			mp[noww]=cnt;
		}
		vec[mp[noww]].push_back({s1,s2});
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1==t2){
			for(int i=0;i<vec[0].size();i++){
				if(fi(t1,vec[0][i].first)){
					ans++;
				}
			}
			cout<<ans<<endl;
			continue;
		} 
		f=0;
		while(t1[f]==t2[f]){
			f++;
		}
		l=t1.size()-1;
		while(t1[l]==t2[l]){
			l--;
		} 
		noww="";
		noww2="";
		for(int i=f;i<=l;i++){
			noww+=t1[i];
			noww2+=t2[i];
		} 
		noww=noww+noww2;
		nx=mp[noww];
		if(nx==0){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<vec[nx].size();i++){
			if(fi(t1,vec[nx][i].first)&&fi(t2,vec[nx][i].second)){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
