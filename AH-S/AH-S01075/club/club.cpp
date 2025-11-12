#include<bits/stdc++.h>
using namespace std;
/*int t,n;
int a1[100010],a3[100010],a2[100010];
int ans=0;
bool f[100010];
void DFS(int ans0,int v1,int v2,int v3,int cnt){
	if(cnt==n) {
		ans=max(ans,ans0);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]){
			f[i]=false;
			if(v1!=0)DFS(ans0+a1[i],v1-1,v2,v3,cnt+1);
			if(v2!=0)DFS(ans0+a2[i],v1,v2-1,v3,cnt+1);
			if(v3!=0)DFS(ans0+a3[i],v1,v2,v3-1,cnt+1);
			f[i]=true;
		}
	}
}
bool f2,f3;
bool spe1_cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		f2=f3=true;
		cin>>n;ans=0;memset(f,true,sizeof(f));
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0) f2=false;
			if(a3[i]!=0) f3=false;
		}
		if(f2==0&&f3==0){
			sort(a1+1,a1+1+n,spe1_cmp);
			for(int i=1;i<=n/2;i++) ans+=a1[i];
			cout<<ans<<'\n';return 0;
		}
		DFS(0,n/2,n/2,n/2,0);
		cout<<ans<<'\n';
	}
	return 0;
}
*/
int t0;
int n,ans;
int a[100010][5],t[100010][5];
struct node{
	int v[5];
	int w;
}dp[100010][5];
struct tmp{
	int k,b;
}t1[100010];
bool cmp(tmp a,tmp b){
	return a.k>b.k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t0;
	while(t0--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)
			cin>>t[i][1]>>t[i][2]>>t[i][3];
		for(int i=1;i<=n;i++){
			t1[i].k=max(t[i][1],max(t[i][2],t[i][3]));
			t1[i].b=i;
		}
		sort(t1+1,t1+1+n,cmp);
		for(int j=1;j<=3;j++)
			for(int i=1;i<=n;i++){
				a[i][j]=t[t1[i].b][j];
			}
		for(int j=1;j<=3;j++)
			for(int i=1;i<=n;i++){
				dp[i][j].w=0;
				dp[i][j].v[1]=0;
				dp[i][j].v[2]=0;
				dp[i][j].v[3]=0;
			}
		for(int j=1;j<=3;j++){
			dp[1][j].w=a[1][j];
			dp[1][j].v[j]=1;
		}
		for(int i=2;i<=n;i++)
			for(int j=1;j<=3;j++){
				dp[i][j].w=a[i][j];
				for(int q=1;q<i;q++)
					for(int p=1;p<=3;p++)
						if(dp[q][p].w+a[i][j]>dp[i][j].w&&dp[q][p].v[j]<n/2){
							dp[i][j].w=dp[q][p].w+a[i][j];
							for(int k=1;k<=3;k++)
								dp[i][j].v[k]=dp[q][p].v[k];
							dp[i][j].v[j]++;
						}
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				ans=max(ans,dp[i][j].w);
		cout<<ans<<'\n';
	}
	return 0;
}
