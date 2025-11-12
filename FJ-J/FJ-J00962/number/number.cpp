#include<bits/stdc++.h>
using namespace std;
string s,ans;
int b;
priority_queue<int> q;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>=97){
			continue;
		}
		ans+=s[i];
	}
	//cout<<ans<<'\n';
	for(int i=0;i<ans.size()-1;i++){
		q.push(int(ans[i]-48));
	}
	while(!q.empty()){
		int a=q.top();
		cout<<a;
		q.pop();
	}
	return 0;
}

