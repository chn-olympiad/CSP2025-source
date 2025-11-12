#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a=0;
vector<int> v;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back((s[i]-'0'));
			a++;
		}
	}
	sort(v.begin(),v.begin()+a);
	for(int i=a-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}