#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int vis[20];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0') vis[0]++;
		if(s[i]=='1') vis[1]++;
		if(s[i]=='2') vis[2]++;
		if(s[i]=='3') vis[3]++;
		if(s[i]=='4') vis[4]++;
		if(s[i]=='5') vis[5]++;
		if(s[i]=='6') vis[6]++;
		if(s[i]=='7') vis[7]++;
		if(s[i]=='8') vis[8]++;
		if(s[i]=='9') vis[9]++;
	}
	for(int i=9;i>=0;i--){
		if(vis[i]==0) continue;
		for(int j=1;j<=vis[i];j++){
			cout<<i;
		}
	}
	return 0;
}

