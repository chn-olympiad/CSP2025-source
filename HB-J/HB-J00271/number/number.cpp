#include<bits/stdc++.h>
using namespace std;
string s,s1;
int k,m;
priority_queue<int>q;
int pow(int x,int y){
	int cnt=1;
	for(int i=1;i<=y;i++){
		cnt=cnt*x;
	}
	return cnt;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])){
			s1+=s[i];
			k=stoi(s1);
			q.push(k);
			s1="";
		}
	}
	m=q.size();
	for(int i=1;i<=m;i++){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
