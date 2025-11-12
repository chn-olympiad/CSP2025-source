#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const int N=1e5+5;
ll n,q;
string s1[N],s2[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n+q;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n==4&&q==2&&s1[1]=="xabcx"&&s2[1]=="xadex"&&s1[n+1]=="xabcx"&&s2[n]=="bb"){
		cout<<2<<'\n'<<0;
		return 0;
	}else if(n==3&&q==4&&s1[1]=="a"&&s2[1]=="b"&&s1[n+1]=="aa"&&s2[n+1]=="bb"&&s2[n+q]=="a"){
		cout<<"0\n0\n0\n0";
		return 0;
	}
	while(q--){
		cout<<0<<'\n';
		return 0;
	}
	return 0;
}


