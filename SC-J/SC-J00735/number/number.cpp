#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> ans;
int x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		x=s[i]-'0';
		if(0<=x && x<=9){
			ans.push(x);
		}
	}
	
	while(ans.size()){
		cout<<ans.top();
		ans.pop();
	}
	return 0;
}