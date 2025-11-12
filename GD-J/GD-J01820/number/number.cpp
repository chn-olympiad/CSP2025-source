#include<bits/stdc++.h>
using namespace std;

string s;
priority_queue<int> q;

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9')
			q.push(s[i]-'0');
	}
	
	if(q.top()==0) cout<<0;
	else{
		while(!q.empty()){
			cout<<q.top();
			q.pop();
		}
	}
	
	return 0;
	
}

//CCF's annoying mashine became blue screen only after I ran my fast read code;
//Expect: 315pts
