#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005],a[500005],res;
int n,k,l,flag;
struct node{
	int l,r,sum;
}T[500005];
struct ans{
	int l,r,id,ans;
}f[500006],now;

void pushup(int id){
	T[id].sum=T[id*2].sum^T[id*2+1].sum;
}
void build(int id,int l,int r){
	T[id].l=l,T[id].r=r;
	if(T[id].l==T[id].r){
		T[id].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	pushup(id);
} 
int query(int id,int x,int y){
	if(T[id].l==0||T[id].r==0) return 0;
	if(T[id].l==x&&T[id].r==y){
		return T[id].sum;
	}
	int mid=(T[id].l+T[id].r)/2;
	if(y<=mid) return query(id*2,x,y);
	else if(x>mid) return query(id*2+1,x,y);
	else return query(id*2,x,mid)^query(id*2+1,mid+1,y);
}
queue<ans> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=1;
		if(a[i]==1) l++;
	}
	if(!flag){
		cout<<l;
		return 0;
	}
	int base=1;
	build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(query(1,i,j)==k){
				 ans p;
				 p.l=i,p.r=j,p.id=base,p.ans=1;
                 q.push(p);
                 base++;
		     }}
	}
    while(!q.empty()){
    	ans c=q.front();
    	q.pop();
    	res=max(res,c.ans);
    	if(c.id==base||c.r==n) continue;
    	int flag=0;
    	for(int i=c.id;i<=base;i++){
    		if(c.r<f[i].l){
    			ans t=f[i];
    			t.ans++;
    			flag=1;
    			q.push(t);
			}
		}
	}
	cout<<res;
	return 0;
}
