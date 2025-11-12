#include<bits/stdc++.h>
using namespace std;
string s;
int len,a;
priority_queue<int> ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a=s[i]-'0';
			ans.push(a);
		}
	}
	if(ans.top()==0){
		printf("0");
		return 0;
	}
	while(!ans.empty()){
		printf("%d",ans.top());
		ans.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}