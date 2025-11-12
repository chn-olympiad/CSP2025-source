#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
vector<int> a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9'&&s[i]>='0'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();++i){
		cout<<a[i];
	}
	return 0;
}
