#include<bits/stdc++.h>
using namespace std;
const int qy=998244353;
int n,m,z,a[505],l;
string s;
bool vis[505];
unsigned long long cnt;
void dfs(int d){
	if(d==n&&l==m){
		cnt++;
		return;
	}
	if(d==n||l>m){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(s[i]='1'||d-l<a[i]){
				l++;
			}	
			vis[i]=1;
			dfs(++d);
			vis[i]=0;
			if(s[i]='1'||d-l<a[i]){
				l--;
			}
		}		
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<cnt%qy;
	return 0;
}
