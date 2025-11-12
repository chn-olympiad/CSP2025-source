#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
priority_queue<char> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]);
		}
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}