#include<bits/stdc++.h>
using namespace std;
int n,q;
int ans;
bool v[200010];
string s[200010];
map<string,int> mp;
string x1,x2;
int len;
void dfs(string x){
	if(x == x2){
		ans++;
		return ;	
	}
	for(int i = 0;i<len;i++){
		for(int j = i;j<len;j++){
			string tmp = x.substr(i,j-i+1);
			if(mp[tmp]&&v[mp[tmp]] == 0){
				dfs(x.substr(0,i)+s[mp[tmp]]+x.substr(j+1,n-j));
				v[mp[tmp]] = 1;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		string x;
		cin>>x;
		mp[x] = i;
		cin>>s[i];
	}
	while(q--){
		ans = 0;
		memset(v,0,sizeof(v));
		cin>>x1>>x2;
		len = x1.length();
		dfs(x1);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
