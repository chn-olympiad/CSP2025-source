#include<bits/stdc++.h>
using namespace std;
int T,n,a[111111][11],tmp[111111],ans,maxx2,maxx1;
void dfs(int i,int l,int m,int r,int sum){
	if(i>n){
		ans=max(sum,ans);
		return;
	}
	if(l!=0)dfs(i+1,l-1,m,r,sum+a[i][0]);
	if(m!=0)dfs(i+1,l,m-1,r,sum+a[i][1]);
	if(r!=0)dfs(i+1,l,m,r-1,sum+a[i][2]);
}
bool cmp(int a,int b){
	if(a!=b)return a>b;
	return 1;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			tmp[i]=a[i][0];
			maxx1=max(maxx1,a[i][1]);
			maxx2=max(maxx2,a[i][2]);
		}
		if(maxx1==0&&maxx2==0){
			sort(tmp+1,tmp+n+1,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i][1];
		}
		else if(n<=20)dfs(1,n/2,n/2,n/2,0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
