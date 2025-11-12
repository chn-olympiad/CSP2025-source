#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int,vector<int>,less<int> >q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			q.push((int)s[i]-'0');
		}
	}
	while(!q.empty()){
		printf("%d",q.top());
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
