#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dou;

const int N = 2e5 + 10;

str s;
priority_queue<ll> q;

void solve(){
	cin >> s;
	char ch = '0';
	for(int i=0;i<s.size();i++){
		int numb = s[i]-ch;
		if(numb>=0 && numb<=9) q.push(numb);
	}
	while(q.size()){
		int x = q.top();
		cout << x;
		q.pop();
	}
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
