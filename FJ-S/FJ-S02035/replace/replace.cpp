#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int n,T;
map<string,string>p;
signed main(){
	fre("replace");
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		p[a]=b;}
	while(T--){
		string a,b;
		int ans=0;
		cin>>a>>b;
		if(p[a]==b)ans++;
		int la=a.size(),lb=b.size(),k=-1,e=0;
		if(la!=lb){cout<<"0\n";continue;}
		for(int i=0;i<la;i++)
			if(a[i]!=b[i]){
				if(k==-1)k=i;
				else e=i;}
		if(p[a.substr(k,e-1)]!=""){
			if((a.substr(0,k))+(p[a.substr(k,e-1)])+(a.substr(e+1,la))==b)ans++;}		
		cout<<ans<<"\n";}
	return 0;}
/*
CSP2025-S2RP+++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-S2RP+++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-S2RP+++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-S2RP+++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-S2RP+++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-S2RP+++++++++++++++++++++++++++++++++++++++++++++++++
CSP2025-S2RP+++++++++++++++++++++++++++++++++++++++++++++++++
*/
