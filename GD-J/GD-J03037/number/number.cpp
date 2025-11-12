#include<bits/stdc++.h>
using namespace std;
int t[25];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	priority_queue<char>Q;
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9'){
			t[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]--){
			cout<<i;
		}
	}
	return 0;
}
