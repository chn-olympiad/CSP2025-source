#include<bits/stdc++.h>
#define int long long
#define PYY pair<int,int>
#define x first
#define y second
using namespace std;
int n,m;
bool ab=1;
map<string,string>mp; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(int i=1;i<=m;i++){
		string s1="",s2="",s3="",s4="";
		int l=-1,r=0,ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
//		cout<<s1<<' '<<s2<<' ';
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				if(l==-1)l=j;
				else r=j;
			}
		}
//		cout<<l<<' '<<r<<' ';
		for(int j=l;j<=r;j++){
			s3+=s1[j];
			s4+=s2[j];
		}
//		cout<<s3<<' '<<s4<<'\n';
		for(auto v:mp){
			if(v.x.find(s3) < v.x.size() && v.y.find(s4) < v.y.size() && s1.find(v.x)<s1.size()&&s2.find(v.y)<s2.size()){
				++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

