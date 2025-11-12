#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn=1e6;
int len;
char c;
string s;
priority_queue<int> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=(int)s.length();
	for(int i=0;i<len;i++){
		c=s[i];
		if(c-'0'>=0&&c-'0'<=9) q.push(c-'0');
	}
	while(!q.empty()){
		cout<<q.top();q.pop();
	}
	return 0;
}//835