#include<bits/stdc++.h>
using namespace std;
char s;
priority_queue<int> m;
char x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0'&&s<='9')
			m.push(s);
	}
	while(!m.empty()){
		x=m.top();
		m.pop();
		cout<<x;
	}	
	cout<<'\n';
	return 0;
}