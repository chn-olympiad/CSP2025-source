#include<bits/stdc++.h>
using namespace std;
long long n,q;
struct node{
	long long next[26];
	bool isend=0;
	string another;
}mp[5000009];long long mapend=1;
void add(string s,string t){
	long long sl=s.size();
	long long v=0;
	for(long long i=0;i<sl;i++){
		if(mp[v].next[s[i]-'a']==0){
			mp[v].next[s[i]-'a']=mapend;
			mapend++;
		}
		v=mp[v].next[s[i]-'a'];
	}
	mp[v].isend=1;
	mp[v].another=t;
	return;
}
long long find(string s,string t,long long l,long long u,long long r){
	long long ans=0;
	long long mapnow=0;
	for(long long i=u;i<l;i++){
		if(mp[mapnow].next[s[i]-'a']!=0){
			mapnow=mp[mapnow].next[s[i]-'a'];
		}
		if(i>r&&mp[mapnow].isend){
			ans++;
		}
	}
	return ans;
}
void init(){
	long long ans=0;
	string s,t;
	cin>>s>>t;
	long long ls=s.size(),lt=t.size();
	if(ls!=lt){
		cout<<0<<endl;
		return;
	}
	long long r;
	for(r=ls-1;s[r]==t[r];r--){
	}
	for(long long i=0;i<ls;i++){
		if(s[i]!=t[i]){
			i=ls;
		}
		ans+=find(s,t,ls,i,r);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		add(s,t);
	}
	for(long long i=1;i<=q;i++){
		init();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
