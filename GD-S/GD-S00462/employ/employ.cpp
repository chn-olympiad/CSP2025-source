#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[502];
int a[502];
bool v[502];
long long an;
void dfs(int x,int t){
	if(x==n){
		if(t>=m){
			an++;	
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==true) continue;
		v[i]=true;
		if(s[x]=='0'||x>c[i]){
			dfs(x+1,t);
		}
		else{
			dfs(x+1,t+1);
		}
		v[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin >>c[i];
	}
	dfs(0,0);
	cout <<an%998244353;
	return 0;
}
