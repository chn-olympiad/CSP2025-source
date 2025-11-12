#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mzk=1e5+5;
int t;
int n,a[mzk][3];
int res1[mzk],dp1[205][205][205];
int flag1,flag2;
void init(){
	flag1=1;
	memset(dp1,0,sizeof(dp1));
	return;
}
struct node1{
	int x,y;
	friend bool operator<(node1 a,node1 b){
		return a.x+b.y>b.x+a.y;
	}
}re[mzk];
struct node2{
	int val,id,pos;
	friend bool operator<(node2 x,node2 y){
		return x.val>y.val;
	}
}maxn[mzk];
void solve(){	
	scanf("%lld",&n);
	flag1=1;flag2=1;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&a[i][0],&a[i][1],&a[i][2]);
		if(a[i][1]!=0||a[i][2]!=0){
			flag1=0;
		}
		if(a[i][2]!=0) flag2=0;
	}
	if(flag1){
		for(int i=1;i<=n;i++){
			res1[i]=a[i][0];
		}
		sort(res1+1,res1+1+n);
		int tot=0;
		for(int i=n;i>=n/2+1;i--){
			tot+=res1[i];
		}
		printf("%lld\n",tot);return;
	}
	if(n<=200){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i&&j<=n/2;j++){
				for(int k=0;k<=i-j&&k<=n/2;k++){
					if(i-j-k>n/2) continue;
					if(i<j+k) continue;
					if(i-1>=j+k){
						dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k]+a[i][2]);
					}
					if(j>=1){
						dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j-1][k]+a[i][0]);
					}
					if(k>=1){
						dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k-1]+a[i][1]);
					}
					//cout<<dp1[i][j][k]<<"m"<<i<<"z"<<j<<"k"<<k<<endl;
					ans=max(ans,dp1[i][j][k]);
				}
			}
		}
		printf("%lld\n",ans);return;
	}
	if(flag2){
		for(int i=1;i<=n;i++){
			re[i].x=a[i][0],re[i].y=a[i][1];	
		}
		sort(re+1,re+1+n);
		int crys=0;
		for(int i=1;i<=n/2;i++){
			crys+=re[i].x; 
		}
		for(int i=n/2+1;i<=n;i++){
			crys+=re[i].y;
		}
		printf("%lld\n",crys);return;
	}
	for(int i=1;i<=n;i++){
		maxn[i].id=i;
		maxn[i].pos=1;maxn[i].val=a[i][0];
		if(a[i][1]>maxn[i].val){
			maxn[i].val=a[i][1];maxn[i].pos=2;
		}
		if(a[i][2]>maxn[i].val){
			maxn[i].val=a[i][2];maxn[i].pos=3;
		}
	}
	sort(maxn+1,maxn+1+n);
	int outpu=0;
	int cnt[4];cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		if(cnt[maxn[i].pos]<=n/2-1){
			cnt[maxn[i].pos]++;outpu+=a[i][maxn[i].pos-1];
		}
		else{
			if(maxn[i].pos==1){
				int num=maxn[i].id;
				if(a[num][1]>a[num][2]){
					cnt[2]++;outpu+=a[num][1];
				} 
				else{
					cnt[3]++;outpu+=a[num][2];
				}
			}
			if(maxn[i].pos==2){
				int num=maxn[i].id;
				if(a[num][0]>a[num][2]){
					cnt[1]++;outpu+=a[num][0];
				} 
				else{
					cnt[3]++;outpu+=a[num][2];
				}
			}
			else{
				int num=maxn[i].id;
				if(a[num][0]>a[num][1]){
					cnt[1]++;outpu+=a[num][0];
				} 
				else{
					cnt[2]++;outpu+=a[num][1];
				}
			}
		}
	}
	printf("%lld\n",outpu);return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		init();solve();
	}
	return 0;
} 
