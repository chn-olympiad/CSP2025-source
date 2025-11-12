#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,k,a[N],dp[N][N],tot,flag[N*N],ans;
struct sd{
	int x,y;
}b[N*N];
bool cmp(sd x,sd y){
	return x.y<y.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		dp[i][i]=a[i];
		sd v;
		v.x=i,v.y=i;
		if(a[i]==k) b[++tot]=v;
		for(int j=1;j<i;j++){
			dp[j][i]=dp[j][i-1]^a[i];
			if(dp[j][i]==k){
				sd u;
				u.x=j,u.y=i;
				b[++tot]=u;
			}
		}
	}
	sort(b+1,b+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		if(!flag[i]){
			ans++;
			//cout<<b[i].x<<' '<<b[i].y<<endl;
		}
		else continue;
		for(int j=i+1;j<=tot;j++){
			if(b[j].x<=b[i].y) flag[j]=1;
		}
	}
	cout<<ans;
	return 0;
} 