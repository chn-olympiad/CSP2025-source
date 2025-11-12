#include <bits/stdc++.h>
using namespace std;
int num[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			++num[str[i]-'0'];
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]--){
			cout<<i;
		}
	}
	return 0;
}
