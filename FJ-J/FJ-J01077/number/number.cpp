#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char c;
	while(cin>>c){
		if(c>='0'&&c<='9'){
			ans.push_back(c-'0');
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans[0]==0){
		cout<<0;
		return 0;
	}
	for(int i : ans){
		cout<<i;
	}
	return 0;
}
