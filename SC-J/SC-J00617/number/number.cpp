#include<bits/stdc++.h>
using namespace std;
string s,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char ch:s){
		if('0'<=ch&&ch<='9')	ans.push_back(ch);
	}
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;
}