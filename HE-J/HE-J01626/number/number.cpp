#include<bits/stdc++.h>
using namespace std;
int ans[1000050]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int vis[15]={};
	string s;
	int idx=0;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-48;
			vis[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(vis[i]!=0){
			vis[i]--;
			ans[idx]=i;
			idx++;
		}
	}
	for(int i=0;i<idx;i++){
		cout<<ans[i];
	}
	return 0;
}
