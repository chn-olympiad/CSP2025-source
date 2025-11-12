#include<bits/stdc++.h>
using namespace std;
string s;
int vis[1000010];
int ans;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i = 0;i < s.size();i++){
		if(s[i] - '0' == 0) vis[0]++;
		if(s[i] - '0' == 1) vis[1]++;
		if(s[i] - '0' == 2) vis[2]++;
		if(s[i] - '0' == 3) vis[3]++;
		if(s[i] - '0' == 4) vis[4]++;
		if(s[i] - '0' == 5) vis[5]++;
		if(s[i] - '0' == 6) vis[6]++;
		if(s[i] - '0' == 7) vis[7]++;
		if(s[i] - '0' == 8) vis[8]++;
		if(s[i] - '0' == 9) vis[9]++;
	}
	for(int j = 9;j >= 0;){
		while(vis[j] > 0){
			vis[j]--;
			ans = ans * 10 + j;
		}
		if(vis[j] == 0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}
