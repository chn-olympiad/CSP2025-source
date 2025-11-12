#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q;
//priority_queue<int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string a;
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			q.push(a[i]-'0');
		}
	}
	while(q.size()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
