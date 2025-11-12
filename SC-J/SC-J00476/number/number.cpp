#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int vis[260];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			vis[s[i]]+=1;
		}
	}
	for(int i='9';i>='0';i--){
		if(vis[i]!=0){
			while(vis[i]!=0){
				cout<<(char)i;
				vis[i]-=1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
