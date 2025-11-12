#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int qp[20];
string s;
void read(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	read();
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			qp[s[i]-'0']++;
		}
	}
	bool p=0;
	for(int i=9;i>=0;i--){
		while(qp[i]!=0){
			cout<<i;
			if(!p&&i==0){
				p=1;
				break;
			}
			qp[i]--;
			p=1;
		}
	}
	if(!p)cout<<0;
	return 0;
}