#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> p;
long long cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			p.push(s[i]-'0');
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<p.top();
		p.pop();
	}
	return 0;
}