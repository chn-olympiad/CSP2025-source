#include <iostream>
using namespace std;
int vis[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>s;
	for(int i=0;i<s.size();++i) if(s[i]>='0'&&s[i]<='9') ++vis[s[i]-'0'];
	for(int i=9;i>=0;--i) for(int j=1;j<=vis[i];++j) cout<<i;
	return 0;
} 
