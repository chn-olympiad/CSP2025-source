#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m;
const int Mod=998244353;
string str;
int a[505],t[505],flag[505],ans;
void dfs(int x){
	if(x>n){
		int naixin=0,succeed=0;
		for(int i=1;i<=n;i++){
			if(a[t[i]]>naixin){
				if(str[i-1]=='0'){
					naixin++;
				}else{
					succeed++;
				}
			}else{
				naixin++;
			}
		}
		if(succeed>=m){
			ans=(ans+1)%Mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			t[i]=x;
			flag[i]=1;
			dfs(x+1);
			flag[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
