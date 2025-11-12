#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,maxn,a[500010],sumxor[500010];
struct num{
	int l,r;
}b[1000010];
struct num2{
	int d,R;
}dp[10010][10010];
bool cmp(const num &x,const num &y){
	if(x.l!=y.l) return x.l<y.l;
	return x.r<y.r;
}
void ans(int m,int sum,int R){
	if(m>=cnt){
		maxn=max(maxn,sum);
		return ;
	}
	if(b[m].l>R){
		ans(m+1,sum+1,b[m].r);
	}
	ans(m+1,sum,R);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	sumxor[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sumxor[i]=(sumxor[i-1]^a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((sumxor[r]^sumxor[l-1])==k){
				b[++cnt].l=l;
				b[cnt].r=r;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			if(dp[i-1][j].R<b[i].l&&j<=i){
				dp[i][j].d=dp[i-1][j].d+1;
				dp[i][j].R=b[j].r;
			}
			else{
				dp[i][j].d=dp[i-1][j].d;
				dp[i][j].R=dp[i-1][j].R;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		maxn=max(maxn,dp[cnt][i].d);
	}
	cout<<maxn;
	return 0;
}
