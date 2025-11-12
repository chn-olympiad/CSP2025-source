#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int vis[20];
	memset(vis,0,sizeof(vis));
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int p=s[i]-'0';
			vis[p]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=vis[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
