#include<bits/stdc++.h>
#include <queue>
using namespace std;
string s;
priority_queue <int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0' && s[i]<='9'){
			a.push(s[i]-'0');
		}
		
	}
	while(!a.empty()){
		cout<<a.top();
		a.pop();
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 