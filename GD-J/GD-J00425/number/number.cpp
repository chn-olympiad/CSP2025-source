#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int u=1;
	int n=s.size();
	priority_queue<int> a;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push(s[i]-'0');
		}
	}
	while(a.size()){
		cout<<a.top();
		a.pop();
	}
	fclose(stdin);
	fclose(stdout);
}
