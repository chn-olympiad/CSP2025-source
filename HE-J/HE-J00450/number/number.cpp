#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> num;
int r[1000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num.push(int(s[i])-'0');
	while(!num.empty()){
		cout << num.top();
		num.pop();
	}
	return 0;
}
