#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[100005],b[100005],c[100005],maxb[100005],maxc[100005],cnt[4],ans,A,B;
bool cmp(int x,int y){
	return x>y;
}
void dfsB(int i,int sum,int aa,int bb){
	if(i==n+1){
		ans=max(ans,sum);
		return;
	}
	if(sum+maxb[n]-maxb[i-1]<ans) return;
	if(aa<n/2) dfsB(i+1,sum+a[i],aa+1,bb);
	if(bb<n/2) dfsB(i+1,sum+b[i],aa,bb+1);
}
void dfsC(int i,int sum,int aa,int bb,int cc){
	if(i==n+1){
		ans=max(ans,sum);
		return;
	}
	if(sum+maxc[n]-maxc[i-1]<ans) return;
	if(aa<n/2) dfsC(i+1,sum+a[i],aa+1,bb,cc);
	if(bb<n/2) dfsC(i+1,sum+b[i],aa,bb+1,cc);
	if(cc<n/2) dfsC(i+1,sum+c[i],aa,bb,cc+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		A=B=1;
		for(int i = 1;i <= n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			maxb[i]=maxb[i-1]+max(a[i],b[i]);
			maxc[i]=maxc[i-1]+max(a[i],max(b[i],c[i]));
			if(b[i]!=0) A=0;
			if(c[i]!=0) A=B=0;
		}
		if(A) for(int i = 1;i <= n/2;i++) ans+=a[i];
		else if(B) dfsB(1,0,0,0);
		else dfsC(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
