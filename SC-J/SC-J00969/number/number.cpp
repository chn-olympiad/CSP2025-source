#include<bits/stdc++.h>
using namespace std;
char x;
priority_queue<long long>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>x){
		if('0'<=x&&x<='9'){
			long long temp=x-'0';
			q.push(temp);
		}
	}
	if(q.top()==0){
		cout<<0<<endl;
		return 0;
	}
	while(q.size()){
		cout<<q.top();
		q.pop();
	}

	return 0;
}