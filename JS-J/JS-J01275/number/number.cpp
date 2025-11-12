#include<bits/stdc++.h>
using namespace std;
long long cnt;
string s;
priority_queue<int>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long v=s.size();
	for(long long i=0;i<v;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int n=s[i]-'0';
			cnt++;
			q.push(n);
		}
	}
	for(long long i=1;i<=cnt;i++){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
