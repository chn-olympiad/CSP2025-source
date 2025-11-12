//GZ-S00110 周洵羽 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans,a[1000005];
string s;
bool t[1000005];
void dfs(int x,int num,int cnt,int shi,int cntt){
	
	t[x]=1;
	if(s[cntt-1]=='0') shi++;
	else if(shi<a[x]) cnt++;
	else shi++;
	for(int i=1;i<=n;i++){
		if(t[i]==0) dfs(i,num,cnt,shi,cntt+1);
	}
	t[x]=0;
	if(cnt>=num && cntt==n){
		ans++;
		return ;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//dfs(0,m,0,0,0);
	for(int i=1;i<=n;i++){
		dfs(i,m,0,0,1);
	}
	cout<<ans;
	return 0;
}
