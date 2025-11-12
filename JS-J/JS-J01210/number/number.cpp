#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
map<int,long long> m;
string s;
int main(){
	ios::sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			m[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(m[i]!=0){
			while(m[i]--){
				cout<<i;
			}
		}
	}
	return 0;
}
