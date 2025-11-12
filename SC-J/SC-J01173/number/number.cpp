#include<bits/stdc++.h>
using namespace std;
string a;
priority_queue<int> pq;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]<='9'&&a[i]>='0'){
			pq.push(a[i]-'0');
		}
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
	return 0;
} 