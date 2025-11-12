#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string s;
priority_queue<char> q;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){if(s[i]>='0' && s[i]<='9')q.push(s[i]);}
	while(!q.empty()){cout<<q.top();q.pop();}
	return 0;
}