#include<bits\stdc++.h>
using namespace std;
priority_queue<int> q;
string s;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' and s[i]<='9'){
			q.push(s[i]-'0');
		}
	}while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
} 
