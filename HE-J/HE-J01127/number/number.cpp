#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define endl '\n'//½»»¥Ìâ×¢ÊÍ
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
inline ll read(){
	ll x=0,t=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')t=-t;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return t*x;
}
string s;
int a[15],n;
signed main(){
	file("number");
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)a[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}

