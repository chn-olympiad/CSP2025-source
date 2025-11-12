#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	priority_queue<int> a;
	string s;
	cin>>s;
	long long jishu=0;
	for(long long p=0;p<s.size();p++){
		if(s[p]>='0' && s[p]<='9'){
			a.push(s[p]-'0');
			jishu++;
		}
	}
	for(long long p=0;p<jishu;p++){
		cout<<a.top();
		a.pop();
	}
	return 0;
}
