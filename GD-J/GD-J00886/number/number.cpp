#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	priority_queue<int> q;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-'0');
		}
	}
	while(q.size()){
		cout<<q.top();
		q.pop();
	}
	return 0;
} 
