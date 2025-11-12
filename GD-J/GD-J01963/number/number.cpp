#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string pjs;
	cin>>pjs;
	priority_queue<int> pjq;
	for(int i=0;i<pjs.size();i++){
		if(pjs[i]>='0' && pjs[i]<='9'){
			pjq.push(pjs[i]-'0');
		}
	}
	if(pjq.top()==0)return cout<<0,0;
	while(!pjq.empty()){
		cout<<pjq.top();
		pjq.pop();
	}
	return 0;
} 
