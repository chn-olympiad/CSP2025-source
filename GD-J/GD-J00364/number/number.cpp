#include<bits/stdc++.h>
using namespace std;
int m[1053];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	string s;
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if('0'<=s[i]&&s[i]<='9'){
			int cha=(int)s[i];
			m[cha]++;
		}
	}
	string ans;
	for(int i='9';i>='0';i--){
		for(int j=1;j<=m[i];j++){
			ans+=i;
		}
	}
	cout<<ans;
	return 0;
} 
