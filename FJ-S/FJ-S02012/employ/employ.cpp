#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0,t[510],c[510],ans=0,l[510];
char s[510];
bool vis[510];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int k,int sum){
	
	if(k==n+1){
		/*for(int i=1;i<=n;i++)cout<<l[i]<<" ";
		cout<<sum<<endl;*/
		if(sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		
		if(vis[i])continue;
		vis[i]=1;
		l[k]=i;
		if(t[k]>=c[i]||t[k]==-1)dfs(k+1,sum);
		else dfs(k+1,sum+1);
		vis[i]=0;
	}
	return;
}
void dfs2(int k){
	if(k==n+1){
		int summ=0,out=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')out++;
			if(s[i]=='1'){if(out<c[l[i]])summ++;else out++;}
			
		}
		if(summ>=m)ans++;
		return;
		}
		for(int i=1;i<=n;i++){
			
			if(vis[i])continue;
			vis[i]=1;
			l[k]=i;
			dfs2(k+1);
			vis[i]=0;
		}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')sum++,t[i]=-1;
		else{
			cnt++;
			t[i]=sum;
		}
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(cnt<m){printf("0");return 0;}
	//sort(c+1,c+1+n,cmp);
	if(n>10)dfs(1,0);
	else{
		dfs2(1);
	}
	printf("%d",ans);
	return 0;
}
