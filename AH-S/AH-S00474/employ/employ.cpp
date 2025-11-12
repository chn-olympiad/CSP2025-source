#include<bits/stdc++.h>
using namespace std;
string str;
int c[1000];
int a[15],t[15];
int m,n,sum,x,ans;
void dfs(int u){
	if(u==m+1){
		int su=0,sm=0;
		for(int i=1;i<=m;i++){
			if(str[i-1]=='0'){
				sm++;
			}else{
				if(sm>=c[i]){
					sm++;
				}else{
					su++;
				}
			}
		}
		if(su>=m){
			ans++;
			ans%=998244353;
		}
	}
	for(int i=1;i<=m;i++){
		if(t[i]){
			a[u]=i;
			t[i]=1;
			dfs(u+1);
			t[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n>>str;
	for(int i=0;i<str.size();i++){
		sum+=str[i]-'0';
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
		if(c[i]){
			x++;
		}
	}
	if(sum==m){
		cout<<x;
	}else{
		dfs(1);
	}
	return 0;
}
