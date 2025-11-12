#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue <char> res;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++){
		if(s[i]=='\0')break;
		if(s[i]>=48 && s[i]<=57)res.push(s[i]);
	}
	while(!res.empty()){
		cout<<res.top();
		res.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
