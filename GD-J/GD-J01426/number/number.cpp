#include<bits/stdc++.h>
using namespace std;
priority_queue<int>pq;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			int now=s[i]-'0';
			pq.push(now);
		}
	}
	while(!pq.empty()) {
		cout<<pq.top();
		pq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

