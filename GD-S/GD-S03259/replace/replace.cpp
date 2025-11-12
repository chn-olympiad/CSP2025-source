#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#define endl '\n'
using namespace std;
const int MAXN=200005;
int n,q;
string s1[MAXN],s2[MAXN];
void solve1(){
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				string tmp=t1;
				int k,l;
				for(k=i,l=0;k<t1.size()&&l<s1[j].size();k++,l++){
					if(s1[j][l]!=t1[k]) break;
					if(s2[j][l]!=t2[k]) break;
					tmp[k]=s2[j][l];
				}
				if(l!=s1[j].size()) continue;
				ans+=(tmp==t2);
			}
		}
		cout<<ans<<endl;
	}
}
map<int,int> mp;
void solve2(){
	for(int i=1;i<=n;i++){
		int b1,b2;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b') b1=j;
			if(s2[i][j]=='b') b2=j;
		}
		mp[b2-b1]++;
	} 
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int b1,b2;
		for(int j=0;j<t1.size();j++){
			if(t1[j]=='b') b1=j;
			if(t2[j]=='b') b2=j;
		}
		cout<<mp[b2-b1]<<endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	if(n<=200) solve1();
	else solve2();
	return 0;
} 
