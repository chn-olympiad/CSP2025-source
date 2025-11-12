#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
priority_queue<long long>q;
long long ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-'0');
		}
	}
	while(!q.empty()){
		ans=ans*10+q.top();
		q.pop();
	}
	cout<<ans<<endl;
	return 0;
}
