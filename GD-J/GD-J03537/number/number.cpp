#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> q;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(scanf("%c",&c)!=EOF){
		if(c>='0' && c<='9') q.push(c-'0');
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	
	return 0; //expect: 100 pts
}
