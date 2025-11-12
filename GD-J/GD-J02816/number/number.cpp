#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]<='9'&&s[i]>='0'){
			int x=s[i]-'0';
			pq.push(x);
		}
	}
	while(!pq.empty()){
		int x=pq.top();
		cout<<x;
		pq.pop();
	}
	return 0;
}
