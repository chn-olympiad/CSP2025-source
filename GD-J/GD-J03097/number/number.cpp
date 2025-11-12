#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	string s;
	cin>>s;
	int len=s.size();
	vector<int> a;
	int maxx=-1;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
			maxx=max(maxx,s[i]-'0');
		}
	}
	if(maxx==0){
		cout<<0;
		return;
	}
	sort(a.rbegin(),a.rend());
	for(auto i:a){
		cout<<i;
	}
	return;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
