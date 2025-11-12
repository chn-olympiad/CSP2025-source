#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],f[505],cnt,f1[505];
char s[505];
void dfs(int x){
	if(x>n){
		int ch=0,sh=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&sh<a[f[i]]){
				ch++;
			}
			else sh++;
		}
		if(ch>=m)cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f1[i]){
			f[x]=i;
			f1[i]=1;
			dfs(x+1);
			f[x]=0;
			f1[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<cnt;
	return 0;
}