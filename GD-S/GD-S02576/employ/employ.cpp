# include <bits/stdc++.h>
using namespace std;
int n,m,c[505],tot=0,b[505];
char a[505];
void dfs(int mn,int nm,int t){
	if (c[t]>nm-1-mn&&t>0&&a[nm]=='1') mn++;
	if (nm==n){
		if (mn>=m) tot++;
		return;
	}
	for(int i = 1;i<=n;i++){
		if (b[i]==0){
			b[i]=1;
			dfs(mn,nm+1,i);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	dfs(0,0,0);
	cout<<tot%998244353;
	return 0;
}
