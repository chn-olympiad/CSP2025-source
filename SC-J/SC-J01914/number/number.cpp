#include<bits/stdc++.h>
using namespace std;

#define int long long
string s;
int x=0,len=0;
priority_queue<int>q;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-'0');
		}
	}
	x=q.size();
	for(int i=1 , p;i<=x;i++){
		p=q.top();
		q.pop();
		cout<<p;
	}
	return 0;
}
