#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000005];
int x[1000005],y[1000005];
bool vis[1000005],vis2[1000005];
int v;
int ip;
int t;
int ans;
int t2;
struct s{
	int l, r;
}tr[1000005],tr2[1000005];
bool cmp(s g,s h){
	if(g.l!=h.l){
		return g.l<h.l;
	}else{
		return g.r<h.r;
	}
}
void pr(){
	if(ans==ip){
		return;
	}
	for(int i=1;i<=t2;i++){
		if(vis[i]){
			for(int j=tr2[i].l;j<=tr2[i].r;j++){
				if(vis2[j]){
					return;
				}
				vis2[j]=1;
			}
		}
	}
	for(int i=1;i<=t2;i++){
		if(vis[i]){
			for(int j=tr2[i].l;j<=tr2[i].r;j++){
				vis2[j]=0;
			}
		}
	}
	ans=max(ans,ip);
}
void dfs(int iq,int u){
	if(iq==ip+1){
		pr();
	}
	for(int i=u+1;i<=t2;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(iq+1,u);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,q;
	cin>>n>>q;
	bool flag=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
		if(a[i]>1) flag2=0;
	}
	if(q==0&&flag==1){
		cout<<n/2;
		return 0;
	}
	if(flag2==1){
		int o=0;
		if(q==0){
			bool vss[1000005]={0};
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					o++;
				}else if(a[i]==1&&a[i-1]==1&&vss[i-1]==0&&vss[i]==0){
					o++;
					vss[i-1]=1;
					vss[i]=1;
				}
			}
			cout<<o;
		}else if(q==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					o++;
				}
			}
			cout<<o;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x[++v]=i;
			y[v]=j;
		}
	}
//	for(int i=1;i<=v;i++){
//		cout<<x[i]<<' '<<y[i]<<endl;
//	}
	for(int i=1;i<=v;i++){
		int as=a[x[i]];
		for(int k=x[i]+1;k<=y[i];k++){
			as=(as^a[k]);
		}
		if(as==q){
			tr[++t].l=x[i];
			tr[t].r=y[i];
		}
	}
//	for(int i=1;i<=t;i++){
//		cout<<tr[i].l<<' '<<tr[i].r<<endl;
//	}
	sort(tr+1,tr+t+1,cmp);
	tr[0].l=0,tr[0].r=0;
	for(int i=1;i<=t;i++){
		if(tr[i].l>tr[i-1].l){
			tr2[++t2].l=tr[i].l;
			tr2[t2].r=tr[i].r;
		}
	}
	for(int i=1;i<=t2;i++){
		ip=i;
		dfs(1,0);
	}
	cout<<ans;
	return 0;
}
/*
37 0
1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 0 0 1 1 0 1 0 1 1 0 1 0 1 0 1 1 0 1 0

*/