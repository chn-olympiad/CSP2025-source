#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	priority_queue< int,vector<int>,less<int> > que;
	string s;
	cin>>s;
	int size=0;
	char cha[s.size()];
	//char'0'=int 48
	for(int a=0;a<s.size();a++){
		cha[a]=char(s[a]);
		if(cha[a]>='0'&&cha[a]<='9'){
			que.push(int(cha[a])-48);
			size++;
		}
	}
	for(int a=0;a<size;a++){
		cout<<que.top();
		que.pop();
	}
} 
