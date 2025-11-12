#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,x,a[N],tot,dp[N][2],k;
struct Side{
	int l,r;
}p[N]; 
bool cmp(Side A,Side B){
	if(A.r==B.r)return A.l<B.l;
	return A.r<B.r;
} 
void init(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=i;j++){
			a[j]^=x;
			if(a[j]==k){
				tot++;
				p[tot].l=j;
				p[tot].r=i;
			}
		}
	}
	sort(p+1,p+1+tot,cmp);
	//for(int i=1;i<=tot;i++)cout<<p[i].l<<" "<<p[i].r<<"\n"; 
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	init();
	for(int i=1;i<=tot;i++){
		//if(p[i].r==p[i-1].r)continue;
		dp[i][1]=1;
		dp[i][0]=max(dp[i][0],max(dp[i-1][1],dp[i-1][0]));
		for(int j=1;p[j].r<p[i].l;j++){
			dp[i][1]=max(dp[i][1],max(dp[j][0]+1,dp[j][1]+1));
			//dp[i][0]=max(dp[i][0],dp[j][1]);
		}
		for(int j=1;j<=i;j++)dp[i][0]=max(dp[i][0],dp[j][0]); 
	}
	cout<<max(dp[tot][0],dp[tot][1])<<"\n";
	return 0;
}
//前两题应该能过,xixi 
//验证不了正确性，如果骗分能拿25+
//本代码预测50分，实际未知 
