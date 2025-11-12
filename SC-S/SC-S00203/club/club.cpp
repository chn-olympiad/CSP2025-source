#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[10001][5];
bool b[10001][5];
int ans;
bool cmp(int c,int d){
	return c>d;
}
void dfs(int cnt,int l1,int l2,int l3,int sum){
	if(l1>n/2||l2>n/2||l3>n/2)return;
	if(cnt==n+1){
		ans=max(ans,sum);
		return;
	}
	b[cnt][1]=1;
	dfs(cnt+1,l1+1,l2,l3,sum+a[cnt][1]);
	b[cnt][1]=0;
	b[cnt][2]=1;
	dfs(cnt+1,l1,l2+1,l3,sum+a[cnt][2]);
	b[cnt][2]=0;
	b[cnt][3]=1;
	dfs(cnt+1,l1,l2,l3+1,sum+a[cnt][3]);
	b[cnt][3]=0;
}
int p1[10001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(b,0,sizeof b);
		bool j2=0,j3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			p1[i]=a[i][1];
			if(a[i][2]!=0)j2=1;
			if(a[i][3]!=0)j3=1;
		}
		if(j2==0&&j3==0){
			sort(p1+1,p1+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=p1[i];
			}
			cout<<sum<<"\n";
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}