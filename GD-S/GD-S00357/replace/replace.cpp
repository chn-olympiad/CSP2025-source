#include<bits/stdc++.h>
using namespace std;
string jiequ(string a,long long i,long long b){
	string s="";
	int k=b+i;
	for(;i<k;i++)s+=a[i];
	return s;}
string th(string s,string a,string b){
	long long i=0,k=a.length();
	for(;i<s.length();){
		while(s[i]!=a[0]&&i<s.length())i++;
		if(jiequ(s,i,k)==a){
			s=jiequ(s,0,i)+b+jiequ(s,i+k,s.length()-i-k);
			return s;}
		else i++;}
	return s;}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	string a[n]={},b[n]={},c,d;
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	while(q--){
		cin>>c>>d;
		long long ans=0,k=c.length();
		for(int i=0;i<n;i++){
			if(a[i].length()>k)continue;
			if(th(c,a[i],b[i])==d)ans++;}
		cout<<ans<<'\n';}
	return 0;}
