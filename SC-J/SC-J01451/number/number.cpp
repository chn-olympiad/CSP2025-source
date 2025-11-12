#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+5;
string s;
int a[N],top;
priority_queue<int> q;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
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