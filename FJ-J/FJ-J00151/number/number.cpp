#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
string s,a;
map<char,int>mp;
vector<int>v;
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-48);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i:v){
		a+=to_string(i);
	}
	cout<<a;
	return 0;
} 
