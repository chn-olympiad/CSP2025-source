#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool cmp(char a,char b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	string h;
	for(int i=0;s[i];i++){
		if(isdigit(s[i]))h+=s[i];
	}
	sort(h.begin(),h.end(),cmp);
	cout<<h;
	return 0;
}
