#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],ans,n;
void dfs(int i,int s1,int t1,int s2,int t2,int s3,int t3){
	if(i>n&&t1<=n/2&&t2<=n/2&&t3<=n/2){
		ans=max(s1+s2+s3,ans);
		return ;
	}
	if(t1>n/2){
		return ;
	}
	if(t2>n/2){
		return ;
	}
	if(t3>n/2){
		return ;
	}
	dfs(i+1,s1+a[i],t1+1,s2,t2,s3,t3);
	dfs(i+1,s1,t1,s2+b[i],t2+1,s3,t3);
	dfs(i+1,s1,t1,s2,t2,s3+c[i],t3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int tmp=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0){
				tmp=1;
			}
		}
		if(!tmp){
			sort(a+1,a+1+n);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0,0,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
