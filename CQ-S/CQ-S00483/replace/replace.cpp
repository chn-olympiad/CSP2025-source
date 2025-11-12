#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
int n,q;
const int N=2e5+10;
string s[N];
int count(string s,string t){
	int n=s.size(),m=t.size();
	s='#'+s;
	t='#'+t;
	int ret=0;
	for(int i=1;i<=n-m+1;i++){
		bool f=true;
		for(int j=i;j<=i+m-1;j++){
			if(s[j]!=t[j-i+1]) f=false;
		}
		if(f) ret++;
	}
//	cout<<"count"<<s<<" "<<t<<"="<<ret<<"\n";
	return ret;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string t,r;
		cin>>t>>r;
		for(int j=0;j<t.size();j++){
			s[i]+=t[j];
			s[i]+=r[j];
		}
	}
	while(q--){
		string t,r;
		cin>>t>>r;
		if(t.size()!=r.size()){
			cout<<0<<"\n";
			continue;
		}
		string st="";
		for(int i=0;i<t.size();i++){
			st+=t[i];
			st+=r[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(count(st,s[i])==1) ans++;
		} 
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
