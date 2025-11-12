#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<int>P(10,0);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')P[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(P[i]!=0){
			while(P[i]--){
				cout<<i;	
			}
		}
	}
	return 0;
}