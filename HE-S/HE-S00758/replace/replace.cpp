#include<bits/stdc++.h>
using namespace std;

const int MN=1e3+10;
int n,q;
string st,ed,s1[MN],s2[MN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s="114514";

	cin>>n>>q;

	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];

	while(q--){
		int cnt=0;
		cin>>st>>ed;
		for(int i=1;i<=n;i++){
			if(st.find(s1[i])==st.end()) continue;//skip this str
			
			int pos=st.find(s1[i])-st;

			st.replace(pos,s1[i].size(),s2[i]);
			
			if(st==ed) cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
