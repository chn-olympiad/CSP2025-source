#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],ss=0;
bool b[501];
string s;
void dfs(int k,int x,int sum){
	if(k==n+1){
		if(sum>=m) ss=(ss+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++)
		if(b[i]==0){
			b[i]=1;
			if(s[k-1]=='1'){
				if(x>=a[i]) dfs(k+1,x+1,sum);
				else dfs(k+1,x,sum+1);
			}
			else
				dfs(k+1,x+1,sum);
			b[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0);
	cout<<ss;
}
