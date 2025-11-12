#include<bits/stdc++.h>
using namespace std;
int n,k,tot,nm,qs,vis[500005],a[500005],add[500005];
struct num{
	int l,r;
}q[500005];
bool cmp(const num &x,const num &y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		add[i]=add[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int rs=add[i-1]^add[j];
			if(rs==k){
				tot++;
				q[tot].l=i;
				q[tot].r=j;
				int sc=1;
				while(q[tot-sc].r>=q[tot].r){
					vis[tot-sc]=true;
					sc++;
				}
				if(!vis[tot-sc]&&q[tot-sc].r<=q[tot].l) vis[tot]=true;
				break;
			}
		}
	}
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=tot;i++){
		if(!vis[i]&&qs<=q[i].l){
			cout<<q[i].l<<" "<<q[i].r<<endl;
			qs=q[i].r;
			nm++;
		}
	}
	cout<<nm;
	return 0;
}
