#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
int cnt[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	for(char i:s){
		if(i>='0'&&i<='9')cnt[i-'0']++; 
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--)cout<<i;
	}
	return 0; 
}
