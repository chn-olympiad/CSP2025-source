#include<bits/stdc++.h>
using namespace std;
priority_queue<int>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),num=0;
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			q.push(s[i]-'0');
			num++;
		}
	}
	for(int i=1;i<=num;i++){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
