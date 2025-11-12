#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> pq;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			pq.push(s[i]-'0');
		}
	}
	while(!pq.empty()){
		int f=pq.top();
		cout<<f;
		pq.pop();
	}
	return 0;
}