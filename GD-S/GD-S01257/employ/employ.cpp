#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod=998244353;
int a[100];
int b[100];
bool t[100];
string s;
int ans;
int n,m;
void dfs(int x,int j){
	b[j]=x;
	if(j==n){
		int ren=0;
		int k=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0' || k>=a[b[i]]){
				k++;
			}else{
				ren++;
			}
		}
		if(ren>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!t[i]){
			t[i]=1;
			dfs(i,j+1);
			t[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	s="/"+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans%mod;
	return 0;
}

