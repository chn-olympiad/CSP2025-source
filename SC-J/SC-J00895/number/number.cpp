#include<bits/stdc++.h>
using namespace std;
string st;
map<int,int> mp; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>st;
	priority_queue<int> q;
	for(int i=0;i<st.size();i++){
		if('0'<=st[i]&&st[i]<='9'){
			mp[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(mp[i]){
			cout<<i;
			mp[i]--;
		}
	}
	return 0;
} 