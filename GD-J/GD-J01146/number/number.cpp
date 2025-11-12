#include<bits/stdc++.h>
using namespace std;
char s[100009];
int ans,i;
priority_queue<int> pq;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	while(s[i]!='\0'){
		if(s[i]>='0'&&s[i]<='9'){
			int temp=s[i]-'0';
			pq.push(temp);
		}
		i++;
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
	return 0;
} 
