#include<bits/stdc++.h>
using namespace std;
int n,Q;
long long ans;
string s1,s2;
map<string,string> mp;
void get(int l,int r){
	string x="",y="",z="",q="";
	int i=0;
	for(;i<l;i++){
		if(s1[i]!=s2[i])return;
		x+=s1[i];
	}
	for(;i<r;i++){
		y+=s1[i];
		q+=s2[i];
	}
	if(mp[y].size()==0)return;
	for(;i<s1.size();i++){
		if(s1[i]!=s2[i])return;
		z+=s1[i];
	}
	if(mp[y]==q)ans++;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		string p,q;
		cin>>p>>q;
		mp[p]=q;
		mp[q]=p;
	}
	while(Q--){
		ans=0;
		cin>>s1>>s2;
		if(s1==s2){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<s1.size()-1;i++)
			for(int j=i+1;j<=s1.size();j++)
				get(i,j);
		cout<<ans<<"\n";
	}
	return 0;
}
