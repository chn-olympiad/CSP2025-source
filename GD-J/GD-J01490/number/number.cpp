#include<bits/stdc++.h>
using namespace std;
char a[1145140];
string ans;
priority_queue<int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	for(int i=0;i<1000000;i++){
		if(a[i]>='0'&&a[i]<='9'){
			q.push(a[i]-'0');
		}
	}
	if(q.top()==0){
		cout<<0;
		return 0;
	}
	while(!q.empty()){
		printf("%d",q.top());
		q.pop();
	}
	return 0;
} 
