#include<bits/stdc++.h>
using namespace std;
int n,ans=-1;
int a[5005];
void dfs(int l,int r,int p){
	if(p==n)return;
	ans++;
	int x=a[l],maxn=0,j=l;
	for(int i=l;i<=p;i++){
		if(a[j]>maxn)maxn=a[j];
		j++;
}
	for(int i=l;i<=n;i++){
		if(x>2*maxn)dfs(i,p,i);
		else if(x>2*maxn)dfs(i,p+1,i);
		x+=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(1,1,1);
	cout<<ans;
	return 0;
}
