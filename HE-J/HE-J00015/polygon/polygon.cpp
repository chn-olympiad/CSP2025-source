#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,gm,i,m=-1,now[5005],l;
void dfs(int x){
	if(x>n)return;
	now[x]=m;
	m=max(m,a[x]);
	gm++;
	l+=a[x];
	if(gm>=3&&l>m*2)ans++;
	dfs(x+1);
	gm--;
	m=now[x];
	l-=a[x];
	dfs(x+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
