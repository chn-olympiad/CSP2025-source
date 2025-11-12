#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+5;
const int mod=1e9+7;
int n,k,a[mx],sum[mx],cnt,cnt1,ans,vis[mx];
struct node{
	int l,r,v;
}b[mx];
bool cmp(node x,node y){
	if(x.l==y.l)return x.r<y.r;
	else return x.l<y.l;
} 
void dfs(int x,int siz){
	if(x>cnt1)return;
	ans=max(ans,siz);
	vis[x]=1;
	for(int i=x;i<=cnt1;i++){
		x=i-1;
		if(!vis[i]){
			if(b[x].r<b[i].l){
				vis[i]=1;
				dfs(i,siz+1);
				vis[i]=0;
			}
			else if(a[x+1]==k){
				vis[i]=1;
				dfs(i,siz+1);
				vis[i]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	int flag=0,flag2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1)flag=1;
		if(a[i]==1)cnt++;
		if(a[i]>1)flag2=1;
	}
	if(k==0&&flag==0){
		cout<<n/2;
		return 0;
	}
	else if(k==0&&flag2==0){
		cout<<cnt/2;
		return 0;
	}
	if(k==1&&flag2==0){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int val=sum[j]^sum[i-1];
			if(val==k){
				b[++cnt1].l=i;
				b[cnt1].r=j;
			}
		}
	}
	sort(b+1,b+cnt1+1,cmp);
	for(int i=1;i<=cnt1;i++){
		memset(vis,0,sizeof vis);
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}