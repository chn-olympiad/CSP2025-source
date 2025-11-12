#include <bits/stdc++.h>

using namespace std;

string st;
bool tf=0;
int len;
priority_queue<int , vector <int> , less <> > Q_;

signed main(){
	freopen("number.in" , "r" ,stdin);
	freopen("number.out" , "w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> st;
	
	len = st.size();
	
	for(int i=0; i<len ;i++){
		if(st[i] <= '9' and st[i] >= '0'){
			tf = true;
			
			Q_.push(st[i]-'0');
		}
	}
	
	while (!Q_.empty()){
		cout << Q_.top();
		
		Q_.pop();
	}
	
	return 0;
}
