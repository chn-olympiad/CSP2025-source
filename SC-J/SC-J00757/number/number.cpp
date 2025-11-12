#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue <char> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0' && s[i]<='9') q.push(s[i]);	
	while(!q.empty()){
		printf("%c",q.top());
		q.pop();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}