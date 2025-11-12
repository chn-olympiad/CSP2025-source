#include<bits/stdc++.h>
using namespace std;

const int NM = 10;
int T[NM+4];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	for(const char& c : s){
		if(isdigit(c)) T[c-'0']++;
	}
	for(int i = 9;i >= 0;i--){
		while(T[i] > 0) cout<<i,T[i]--;
	}
	return 0;
}
