#include<bits/stdc++.h>
using namespace std;
string s;
multiset<int> st;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(auto v:s){
		if(v>='0'&&v<='9'){
			st.insert(-int(v-'0'));
		}
	}
	for(auto v:st){
		cout<<-v;
	}
	return 0;
}