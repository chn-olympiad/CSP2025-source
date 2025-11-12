#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
priority_queue <int> pq;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>s+1;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++) {
		if(s[i]>='0'&&s[i]<='9') {
			pq.push(s[i]-'0');
		}
	}
	while(!pq.empty()) {
		cout<<pq.top();
		pq.pop();
	}
	return 0;
}
