#include<bits/stdc++.h>
using namespace std;
namespace qhx{
	int n,m,k,fa[10005],b[15][10005],idx;
	long long c[15],ans,cnt=2e18,kkk;
	int ksm(int a,int b){
		if(!b){
			return 1;
		}
		if(b%2==0){
			int kkk=ksm(a,b/2);
			return kkk*kkk;
		}
		if(b%2==1){
			return ksm(a,b-1)*a;
		}
	}
	struct node{
		int x;
		int y;
		int val;
	}a[2000005];
	bool cmp(node x,node y){
		return x.val<y.val;
	}
	int findd(int x){
		if(fa[x]==x){
			return x;
		}
		return fa[x]=findd(fa[x]);
	}
	void kru(int x){
		int cntt=0;
		sort(a+1,a+1+idx,cmp);
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		for(int i=1;i<=idx;i++){
			int pa=findd(a[i].x),pb=findd(a[i].y);
			if(pa!=pb){
				cntt++; 
				fa[pa]=pb;
				ans+=a[i].val;
				if(ans>cnt||cntt==x-1){
					return;
				}
			}
		}
		return;
	}
	signed main(){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		cin>>n>>m>>k;
		kkk=n;
		for(int i=1;i<=m;i++){
			cin>>a[i].x>>a[i].y>>a[i].val;
			idx++;
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>b[i][j];
			}
		}
		if(k==0){
			kru(0);
			cout<<ans;
			return 0;
		}
		if(k<=5){
			for(int i=0;i<ksm(2,k);i++){
				ans=0;
				int kkkk=0;
				for(int j=1;j<=k;j++){
					if((i>>j-1)&1){
						kkkk++;
						ans+=c[j];
						for(int kk=1;kk<=n;kk++){
							a[++idx].x=n+j;
							a[idx].y=kk;
							a[idx].val=b[j][kk];
						}
					}
				}
				if(ans>=cnt){
					for(int j=1;j<=k;j++){
						if((i>>j-1)&1){
							idx-=n;
						}
					}
					continue;
				}
				kru(n+kkkk);
				cnt=min(cnt,ans);
				for(int j=1;j<=k;j++){
					if((i>>j-1)&1){
						idx-=n;
					}
				}
			}
			cout<<cnt;
			return 0;
		}
		if(k>5){
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(b[i][j]==0){
						for(int kk=1;kk<=m;kk++){
							if(a[kk].x==j){
								a[kk].val=min(a[kk].val,b[i][a[kk].y]);
							}
							if(a[kk].y==j){
								a[kk].val=min(a[kk].val,b[i][a[kk].x]);
							}
						}
					}
				}
			}
			kru(0);
			cout<<ans;
		}
		return 0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	qhx::main();
	return 0;
}
