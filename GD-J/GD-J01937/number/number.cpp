#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>a;
	priority_queue<int> q; 
	for(register ll i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9') q.push(a[i]-'0');
	}
	while(q.size()){
		cout<<q.top();
		q.pop();
	}
	return 0;
} 
