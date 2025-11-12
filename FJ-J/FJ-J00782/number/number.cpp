#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int>q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ss=s.size();
	for(int i=0;i<ss;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-'0');
		}
	}
	while(!q.empty()){
		int x=q.top();
		q.pop();
		cout<<x;
	}
	return 0;
}
