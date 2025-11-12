#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	priority_queue<int,vector<int>,less<int> >pq;
	int len=s.size();
	for(long long w=0;w<len;w++){
		if(s[w]<='9' && s[w]>='0'){
			pq.push(s[w]-'0');
		}
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
