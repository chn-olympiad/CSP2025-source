#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[4],dp[100005],d[100005],e[100005];
struct node{
	int x1,x2,x3;
}a[100005],b[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin >> a[i].x1 >> a[i].x2 >> a[i].x3;
			int c[10];
			c[1]=a[i].x1;
			c[2]=a[i].x2;
			c[3]=a[i].x3;
			sort(c+1,c+4);
			b[i].x1=c[1];
			b[i].x2=c[2];
			b[i].x3=c[3];
			dp[i]=dp[i-1]+c[3]; 
			if(a[i].x1==c[3]){
				x[1]++,e[i]=1;
				continue;
			}
			if(a[i].x2==c[3]){
				x[2]++,e[i]=2;
				continue;
			}
			if(a[i].x3==c[3]){
				x[3]++,e[i]=3;
				continue;
			}
		}
		if(x[1]>n/2){
			int k=1;
			for(int i=1;i<=n;i++){
				if(e[i]==1){
					d[k++]=b[i].x3-b[i].x2;
				}
			}
			sort(d+1,d+k);
			for(int i=1;i<=x[1]-n/2;i++){
				dp[n]-=d[i];
			}
		}
		if(x[2]>n/2){
			int k=1;
			for(int i=1;i<=n;i++){
				if(e[i]==2){
					d[k++]=b[i].x3-b[i].x2;
				}
			}
			sort(d+1,d+k);
			for(int i=1;i<=x[2]-n/2;i++){
				dp[n]-=d[i];
			}
		}
		if(x[3]>n/2){
			int k=1;
			for(int i=1;i<=n;i++){
				if(e[i]==3){
					d[k++]=b[i].x3-b[i].x2;
				}
			}
			sort(d+1,d+k);
			for(int i=1;i<=x[3]-n/2;i++){
				dp[n]-=d[i];
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
} 
