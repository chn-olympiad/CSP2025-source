#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> pq;
long long ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			pq.push(s[i]-'0');
		}
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
	return 0;
}
