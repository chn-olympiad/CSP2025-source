#include<bits/stdc++.h>
using namespace std;
string s;
struct node{
	long long w;
	bool friend operator<(node a,node b){
		return a.w<b.w;
	}
}tmp;
priority_queue<node> q;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			tmp.w=s[i]-'0';
			q.push(tmp);
		}
	}
	while(!q.empty()){
		printf("%d",q.top().w);
		q.pop();
	}
	return 0;
}
