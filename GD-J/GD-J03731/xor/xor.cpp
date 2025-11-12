#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
int n,k,ans=0,cnt0,cnt1;
bool isa,isb;
int a[500005];
vector<node> h;
bool cmp(node a,node b){
	if(a.r-a.l!=b.r-b.l){
		return a.r-a.l<b.r-b.l;
	}
	if(a.l-b.l) return a.l<b.l;
	return a.r<b.r;
}
bool isok(int x){
	int l=h[x].l;
	int r=h[x].r;
	for(int i=l;i<=r;i++){
		if(a[i]) return 0;
	}
	return 1;
}
void be(int x){
	int l=h[x].l;
	int r=h[x].r;
	for(int i=l;i<=r;i++){
		a[i]++;
	}
}
void ed(int x){
	int l=h[x].l;
	int r=h[x].r;
	for(int i=l;i<=r;i++){
		a[i]--;
	}
}
void dfs(int k,int s){
	if(!k) dfs(k+1,s);
	if(k>h.size()) return ;
	ans=max(ans,s);
	dfs(k+1,s);
	if(isok(k)){
		be(k);
		dfs(k+1,s+1);
		ed(k);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	h.push_back({0,0});
	isa=isb=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!a[i]) cnt0++;
		if(a[i]-1) isa=0;
		if(a[i]>1) isb=0;
	}
	if(isa){
		cout<<n/2;
		return 0;
	}
	cnt1=n-cnt0;
	if(isb){
		if(!k){
			cout<<cnt1/2;
		}else{
			cout<<cnt1;
		}
		return 0;
	}
	for(int i=1,res;i<=n;i++){
		res=a[i];
		if(res==k) h.push_back({i,i}); 
		for(int j=i-1;j>0;j--){
			res^=a[j];
			if(res==k) h.push_back({j,i}); 
		}
	}
	memset(a,0,sizeof a);
	sort(h.begin(),h.end(),cmp);
	dfs(0,0);
	printf("%d",ans-1);
	return 0;
}
