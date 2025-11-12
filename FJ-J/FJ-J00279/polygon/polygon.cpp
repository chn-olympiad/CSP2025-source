#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],sum[5010],ans,p[5010];
void dfs(int i,int j,int s,bool b){//i最大值，j此时从j开始延伸，s此时已经有的木棍和，b j是否是选择的第二条边 
	if(j==0||(j==1&&b)) return ;
	int l=1,r=j,tmp=-1;
	if(b) s+=a[j],j--;
	while(l<=r){
		int mid=(l+r)>>1;
		if(s+sum[j]-sum[mid-1]>a[i]) tmp=mid,l=mid+1;
		else r=mid-1;
	}
	int x=s+sum[j]-sum[tmp-1];
	if(x<=a[i]) return ;
	ans=(ans*1LL+p[tmp-1])%mod;
	if(b) dfs(i,j,0,1);
	for(int k=j;k>=tmp;k--) dfs(i,k-1,s,0),s+=a[k];
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
 		cin >> a[i];
	}
	p[0]=1;
	for(int i=1;i<=n;i++) p[i]=p[i-1]*1LL*2%mod;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=3;i<=n;i++){
		dfs(i,i-1,0,1);
	}
	cout << ans;
	return 0;
}
