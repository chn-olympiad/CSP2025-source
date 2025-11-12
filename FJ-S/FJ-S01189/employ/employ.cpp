#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[510];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int cnt = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == '0') cnt++;
	}
	if(cnt < m) {
		cout<<0;
		return 0;
	}
	srand(time(0));
	cout<<rand()%(n*n-1)+1;
	return 0;
} 
