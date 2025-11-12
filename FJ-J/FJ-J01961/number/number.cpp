#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll len;
priority_queue<ll>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			q.push(s[i]-'0');
		}
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
