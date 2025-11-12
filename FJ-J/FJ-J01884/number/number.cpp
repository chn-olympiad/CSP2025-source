#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5;
char v[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int l=0;
	for(int i=0;i<s.length();++i){
		if(s[i]>='0'&&s[i]<='9'){
			v[++l]=s[i];
		}
	}
	sort(v+1,v+1+l,greater<int>());
	if(v[0]=='0'){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=l;++i){
		cout<<v[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

