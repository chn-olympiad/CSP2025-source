#include<bits/stdc++.h>
#define ifo(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
string s;
priority_queue<int> pq;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(),cout.tie();
	cin>>s;
	ifo(i,0,s.size()-1){
		if(s[i]>='0'&&s[i]<='9')pq.push(s[i]-'0');
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
	return 0; 
} 
