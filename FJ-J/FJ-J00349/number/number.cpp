#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<char>ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int a=s[i];
		if(a<97){
			ans.push(s[i]);
			
		}
	}
	for(int i=1;!ans.empty();i++){
		cout<<ans.top();
		ans.pop();
	}
	return 0;
}
