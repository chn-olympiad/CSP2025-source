#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int vis[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9')vis[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=vis[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
