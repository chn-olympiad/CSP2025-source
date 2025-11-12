#include<bits/stdc++.h>
using namespace std;
#define fio(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define tio() freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define cio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using ll=long long;
using pii=pair<int,int>;
const int N=2e5+10;
const int mod=1e9+7;
string t[3];
string s[N][3];
int n,q;
string getstr(string s,int l,int r){
	string res="";
	for(int i=l;i<=r;++i){
		res+=s[i];
	}return res;
}
void replace(string s,int l,int r,string t){
	for(int i=0;i<t.length();++i){
		s[i+l]=t[i];
	}
}
ll sol(int x){
	string tmp="";
	ll res=0;
	int len=s[x][1].length();
	for(int i=0;i<t[1].length()-len;++i){
		tmp=getstr(t[1],i,i+len-1);
		if(tmp==s[x][1]){
			replace(t[1],i,i+len-1,s[x][2]);
			if(t[1]==t[2])++res;
			replace(t[1],i,i+len-1,tmp);
		}
	}
	return res;
}
int main(){
//	tio();
	fio("replace");
	cio();
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;++i){
		cin>>t[1]>>t[2];
		ll ans=0;
		for(int i=1;i<=n;++i){
			ans+=sol(i);
		}
		cout<<ans;
	}
	return 0;
} 
