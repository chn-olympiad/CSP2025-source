#include"bits/stdc++.h"
using namespace std;
string s;int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;++i) if('0'<=s[i] && s[i]<='9') ++a[(s[i]-48)];
	for(int i=9;i>=0;--i){
		while(a[i]>0) cout<<i,--a[i];
	}
	return 0;
}
