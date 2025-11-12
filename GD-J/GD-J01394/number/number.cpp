#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
priority_queue<int,vector<int>,less<int> >q;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			q.push(x);
		}
	}
	while(q.size()){
		int x=q.top();
		q.pop();
		cout<<x;
	}
	return 0;
}
