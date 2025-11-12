#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int maxn=-1; 
priority_queue<int> q;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int k=s[i]-'0';
			maxn=max(k,maxn);
			q.push(k);
		}
	}
	if(maxn==0){
		cout<<"0";
		return 0;
	} 
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
