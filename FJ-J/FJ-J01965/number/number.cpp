#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n;
priority_queue<int>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')
			q.push(s[i]-'0');
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
