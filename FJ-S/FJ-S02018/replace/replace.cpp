#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
string s1,s2;
map<string ,string >mp;
void get(int l,int r){
	string x="",y="",z="",q="";
	int i=0;
	for(;i<l;i++){
		if(s1[i]!=s2[i])return ;
		x+=s1[i];
	}
	for(;i<r;i++){
		y+=s1[i];
		q+=s2[i];
	}
	if(mp[y].size()==0)return;
	for(;i<s1.size();i++){
		if(s1[i]!=s2[i])return ;
		z+=s1[i];
	}
	if(mp[y]==q){
		ans++;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
		mp[s2]=s1;
	}
	for(int i=1;i<=m;i++){
		ans=0;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<s1.size()-1;i++){
			for(int j=i+2;j<=s1.size();j++){
				get(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
