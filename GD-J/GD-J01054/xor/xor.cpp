#include<bits/stdc++.h>
using namespace std;
int in(){
	char c=getchar();
	int f=1,k=0;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k*=10;
		k+=c-'0';
		c=getchar();
	}
	return k*f;
}
const int N=5e5+7;
int a[N],n,k,b[N];
struct node{
	int l,r;
}p[N];
bool cmp(node x,node y){
	if(x.l==y.l)return x.r<y.r;
	return x.l<y.l;
}
bool v[N];
int ans,idx;
void dfs(int num,int u,int r){
	ans=max(ans,num);
	for(int i=u+1;i<=idx;i++){
		if(v[i]||p[i].l<=r||p[i].l==p[i-1].l)continue;
		dfs(num+1,i,p[i].r);
	}
} 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=in();
	k=in();
	for(int i=1;i<=n;i++)a[i]=in();
	for(int i=1;i<=n;i++){
		b[i]=(a[i]^b[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[j]^b[i-1])==k){
				idx++;
				p[idx].l=i;
				p[idx].r=j;
			}
		}
	}
	sort(p+1,p+1+idx,cmp);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
