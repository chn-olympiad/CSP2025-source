#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> l;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]<=57&&s[i]>=48) l.push_back(s[i]-48);
	}
	sort(l.begin(),l.end(),cmp);
	for(long long i=0;i<l.size();i++){
		cout<<l[i];
	}
	return 0;
} 