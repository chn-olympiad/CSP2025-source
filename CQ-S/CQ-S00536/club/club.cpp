#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=2e4; 
int T,n,ans,flg,tns;
struct node{
	int val,cnt;
}a[5][N];
struct node2{
	int f,s,t,tot;
}in[N];
bool cmp(node x,node y){
	return x.val>y.val;
}
bool cmp2(node2 x,node2 y){
	return x.t>y.t;
}
bool cmp3(node2 x,node2 y){
	return x.tot<y.tot;
}
void dfs(int step){
	if(step==0){
		ans=max(tns,ans);
		return;
	}
	if(a[1][0].val<(n/2)){
		a[1][0].val++;
		tns+=in[step].f;
		dfs(step-1);
		tns-=in[step].f;
		a[1][0].val--;
	}
	if(a[2][0].val<(n/2)){
		a[2][0].val++;
		tns+=in[step].s;
		dfs(step-1);
		tns-=in[step].s;
		a[2][0].val--;
	}
	if(a[3][0].val<(n/2)){
		a[3][0].val++;
		tns+=in[step].t;
		dfs(step-1);
		tns-=in[step].t;
		a[3][0].val--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		for(int i=0;i<N;i++){
			in[i].f=in[i].s=in[i].t=in[i].tot=0;
			for(int j=0;j<5;j++){
				a[j][i].val=0;
				a[j][i].cnt=0;
			}
		}
		ans=0,flg=0,tns=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&in[i].f);
			scanf("%lld",&in[i].s);
			scanf("%lld",&in[i].t);
			a[1][i].val=in[i].f;
			a[1][i].cnt=i;
			a[2][i].val=in[i].s;
			a[2][i].cnt=i;
			a[3][i].val=in[i].t;
			a[3][i].cnt=i;
			in[i].tot=in[i].f+in[i].s+in[i].t;
			if(in[i].tot%M){
				flg=1;
			}
		}
		sort(a[1]+1,a[1]+n+1,cmp);
		sort(a[2]+1,a[2]+n+1,cmp);
		sort(a[3]+1,a[3]+n+1,cmp);
		if((a[2][1].val==0)&&(a[3][1].val==0)){
			for(int i=1;i<=n/2;i++){
				ans+=a[1][i].val;
			}
		}else if(a[3][1].val==0){
			for(int i=1;i<=n;i++){
				in[i].t=abs(in[i].f-in[i].s);
			}
			sort(in+1,in+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if((in[i].f)>(in[i].s)){
					if(a[1][0].val<(n/2)){
						a[1][0].val++;
						ans+=in[i].f;
					}else{
						a[2][0].val++;
						ans+=in[i].s;
					}
				}else{
					if(a[2][0].val<(n/2)){
						a[2][0].val++;
						ans+=in[i].s;
					}else{
						a[1][0].val++;
						ans+=in[i].f;
					}
				}
			}
		}else if(!flg){
			sort(in+1,in+n+1,cmp3);
			for(int i=1;i<=n;i++){
				if(in[i].f==M){
					if(a[1][0].val<(n/2)){
						a[1][0].val++;
						ans+=in[i].f;
						continue;
					}
				}
				if(in[i].s==M){
					if(a[2][0].val<(n/2)){
						a[2][0].val++;
						ans+=in[i].s;
						continue;
					}
				}
				if(in[i].t==M){
					if(a[3][0].val<(n/2)){
						a[3][0].val++;
						ans+=in[i].t;
						continue;
					}
				}
			}
		}else{
			dfs(n);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
