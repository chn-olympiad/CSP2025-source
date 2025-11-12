#include<bits/stdc++.h>
using namespace std;
map<string,string>th;
map<string,bool>tt;
int n,q;
string s1,s2,t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		th[s1]=s2;
		tt[s1]=1;
	}
	for(int i=0;i<q;i++){
		cin>>t1>>t2;
		if(tt[t1]&&th[t1]==t2)cout<<1;
		else cout<<0;
		cout<<'\n';
	}
	return 0;
}

