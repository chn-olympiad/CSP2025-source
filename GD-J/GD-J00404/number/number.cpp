#include<bits/stdc++.h>
using namespace std;
string s;
int vis[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int o=s[i]-'0';
			vis[o]++;
		}
	}for(int i=9;i>=0;i--){
		while(vis[i]){
			cout<<i;
			vis[i]--;
		}
	}
	return 0;
} 
