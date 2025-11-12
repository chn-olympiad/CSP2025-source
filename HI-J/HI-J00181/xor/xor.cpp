#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	int l,r;
}g[N];
int n,k,a[N],t=1,ans,aa[N];
bool fx;
bool cmp(node x,node y){
	return x.r<y.r;
}
void dfs(int x,int r,int tt){
	if(fx)return;
	ans=max(ans,x);
	if(aa[r]){
		ans=max(ans,aa[r]);
		return;
	}
	if(r==n||tt==t-1){
		aa[r]=x;
		fx=true;
		return;
	}
	for(int i=tt+1;i<=t;i++)
		if(g[i].l>r){
			dfs(x+1,g[i].r,i);
		}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int xxxx=0,xxxxx;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(xxxxx!=a[i])xxxx=2;
		xxxxx=a[i];
	}
	if(!k&&xxxx){
		if(xxxxx)cout<<n/2;
		else cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n-i;j++){
			int x=a[i];
			for(int kk=i+1;kk<=i+j;kk++)x^=a[kk];
			if(x==k){
				g[t].l=i;
				g[t++].r=i+j;
			}
		}
	sort(g+1,g+t,cmp);
	//for(int i=1;i<t;i++)cout<<g[i].l<<' '<<g[i].r<<"\n";
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
//Ì°ÐÄºÃ°¡ 
