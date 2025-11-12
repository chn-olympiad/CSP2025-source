#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	priority_queue <int>q;	
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-48);		
		}
	}
	int count = 0;
	while(q.empty()){
		count+=1;
		a[count] = q.top();
		q.pop();
	}
	for(int i = 0;i<=count;i++) cout<<a[i];
	return 0;
} 
