#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
//const int N =
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	priority_queue<int>q;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9'){
		q.push(s[i]-'0');
	} 
	while(q.size()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
