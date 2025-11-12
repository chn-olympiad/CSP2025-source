#include <iostream>
#include <vector> 
#include <algorithm> 
#include <cstdio>
#define pb push_back
using namespace std;
string s;
vector<int> a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a.pb(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	if(a[0]==0){
		cout<<0<<endl;
	}
	else{
		for(auto i:a)
			cout<<i;
		cout<<endl; 
	}
	return 0;
}
