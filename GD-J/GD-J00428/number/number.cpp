#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n,bz;
vector<char> v;
bool cmp(char x,char y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s='#'+s;
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			if(s[i]!=0) bz=1;
			v.push_back(s[i]);
		}
	}
	if(bz==0){
		cout<<0<<endl;
		return 0;
	}
	sort(v.begin(),v.end(),cmp);
	for(char i:v){
		cout<<i;
	}
	cout<<endl;
	return 0;
}
