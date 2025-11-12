#include<bits/stdc++.h>
using namespace std;
int n,m,a[560],b[560],c[560],top=0;
char s[560];
int dfs(int nn,int mm,int tt){
	if(nn==n+1&&mm>=m){
		top++;
		top%=998244353;
		return 0;
	}else if(nn<n+1){
		for(int i=1;i<=n;i++){
			if(b[i]==0&&tt<c[i]){
	   			b[i]=1;
				if(a[i]==1){
					nn++;
					mm++;
					dfs(nn,mm,tt);
					nn--;
					mm--;
				}else{
					nn++;
					tt++;
					dfs(nn,mm,tt);
					nn--;
					tt--;
				}
				b[i]=0;
			}else if(b[i]==0&&tt>=c[i]){
				b[i]=1;
				nn++;
				tt++;
				dfs(nn,mm,tt);
				nn--;
				tt--;
				b[i]=0;
			}
		}
	}
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=s[i-1]-'0';
	}
	int o=0;
	for(int i=1;i<=n;i++){
		o+=a[i];
	}
	if(o<m){
		cout<<0;
		return 0;
	}
	dfs(1,0,0);
	top%=998244353;
	cout<<top;
	return 0;
}
