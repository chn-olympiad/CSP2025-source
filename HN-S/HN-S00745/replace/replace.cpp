#include<bits/stdc++.h>
using namespace std;
int n,q;
bool check(string t1,string t2,string s,int st){
	string a="";
	for(int i=0;i<st;i++) a+=t1[i];
	a+=s;
	for(int i=st+s.size();i<t1.size();i++) a+=t1[i];
	if(a==t2) return 1;
	else return 0;
}
struct node{
	string s1,s2;
}s[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].s1>>s[i].s2;
	while(q--){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int f=t1.find(s[i].s1);
			if(f!=-1) if(check(t1,t2,s[i].s2,f)) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
