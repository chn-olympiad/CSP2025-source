#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 505;
const long long M = 998244353;
long long ans;
int n,m,p[MAXN];
bool flag[MAXN];
int list[MAXN];
string t;
void dfs(int i){
	if(i>n){
		int x = 0,r = 0;
		for(int j = 1;j<=n;j++){
			if(p[list[j]]>x&&t[j-1] == '1')r++;
			else x++;
		}
		if(r>=m)ans++;
		return;
	}
	for(int j = 1;j<=n;j++){
		if(flag[j])continue;
		flag[j] = true;
		list[i] = j;
		dfs(i+1);
		flag[j] = false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>t;
	for(int i = 1;i<=n;i++)cin>>p[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*
3 2
101 
1 1 2
*/
