#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int st[N];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			st[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int i1=1;i1<=st[i];i1++){
			cout<<i;
		}
	}
	return 0;
}
/*

5
5

290es1q0
92100
*/