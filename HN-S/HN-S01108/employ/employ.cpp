#include<bits/stdc++.h>
using namespace std;
int c[510];
int n,m;
string s;
int ans=0;
bool book[510];
int f[510];
void dfs(int x,int sum,int crazyguy){
	if(x==n&&sum>=m)ans++;
	if(x==n)return;
	for(int i=1;i<=n;i++){
		if(!book[i]){
			if(crazyguy>=c[i]){
				book[i]=1;
				dfs(x+1,sum,crazyguy+1);
				book[i]=0;
			}
			else{
				book[i]=1;
				if(s[x]=='1')
				dfs(x+1,sum+1,crazyguy);
				else dfs(x+1,sum,crazyguy+1);
				book[i]=0;
			}
			
		}	
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int specheck=0;
	for(int i=0;i<s.size();i++)if(s[i]=='1')specheck++;
	if(specheck<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
