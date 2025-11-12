#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;string s;
	cin>>s;
	n=s.size();
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		if(s[i]<'a') pq.push(s[i]-'0');
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
	return 0;
}
 
