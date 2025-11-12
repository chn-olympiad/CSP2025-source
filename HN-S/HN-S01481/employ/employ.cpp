#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int c[510];
int mod=998244353;
signed  main(){
	freeopen("employ .in","r"stdin);
		freopen("employ.out","r"stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
int n;
int m;
cin>>n>>m;
 string s;
 cin>>s; for(int i=1;i<=n;i++){
 	cin>>c[i];
 	if(!c[i]) --n;
	 } 
	
	 if(n<m)
	 cout<<'0'<<'\n';
 int len= s.size();
 int cnt=0;
 for(int i=0;i<=len-1;i++){
 	if(s[i]=='1') ++cnt;
 }
if(!cnt){

	 long long ans=1;
	 for(int i=1;i<=n;i++){
	 	ans*=i;
	 	ans%=mod;
	 }
cout<<ans<<'\n';
}else{
	cout<<cnt<<'\n';
}
return 0;	
}

