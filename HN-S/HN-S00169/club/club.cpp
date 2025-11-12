#include<bits/stdc++.h>
using namespace std;
int ans=-1;
int n,T;
struct st{
	int w,v,wi,lastv;
}a[100005][5]; 
bool check(string s){
	int t[5]={0},ans2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='0'){
			t[s[i]-'0']++;
			if(t[s[i]-'0']>(n/2)){
				ans=max(ans,0);
				return true;
			}
			else ans2+=a[i+1][s[i]-'0'].v;
		}		
	}ans=max(ans,ans2);
} 
void dfs(string s){
	if(s.size()==n){
		check(s);
		return;
	}
	dfs(s+"0");
	dfs(s+"1");
	dfs(s+"2");
	dfs(s+"3");
	return;
}
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=1;i<=n;i++)cin >> a[i][1].v >> a[i][2].v >> a[i][3].v;
		dfs("");
		cout << ans << '\n';
		ans=0;
	

} 
return 0;
}
