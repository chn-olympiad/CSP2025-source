#include<bits/stdc++.h>
using namespace std;
int sz[12800];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0 ; i <=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			sz[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(sz[i]){
			if(sz[i]!=0){
				cout<<i;
				sz[i]--;
			}
		}
	}
	return 0;
}
