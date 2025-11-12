#include <bits/stdc++.h>
using namespace std;

string s,ans;
bool cmp(char x,char y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	
	for(auto i:s){
		if('0'<=i&&i<='9'){
			ans+=i;
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	
	cout<<ans;
	return 0;
}

