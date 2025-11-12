#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

int n,k,ans,x;
int a[N][25],sum[N][25],k1[25];
int vis[N],_vis[N],vis_[N];
vector<int>v;

void get(int id,int x){
	int i=0;
	while(x>0){
		if(x&1) a[id][i]=1;
		i++;
		x=x>>1;
	}
}

void getk(int x){
	int i=0;
	while(x>0){
		if(x&1) k1[i]=1;
		i++;
		x=x>>1;
	}
}

bool check(int l,int r){
	for(int i=0;i<=20;i++){
		if((sum[r][i]-sum[l-1][i])%2!=k1[i]) return 0;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(0);std::cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	getk(k);
	for(int i=1;i<=n;i++){
		cin>>x;
		get(i,x);
		for(int j=0;j<=20;j++){
			sum[i][j]=a[i][j]+sum[i-1][j];
		}
	}
	for(int len=1;len<=n;len++){
		int last=0;
		for(int i=1;i<=n;i++){
			vis[i]=vis[i-1]+_vis[i];
		}	
		for(int i=1;i<=n;i++){
			vis_[i]=vis_[i-1]+vis[i];
		}
		for(int l=last+1;l+len-1<=n;l++){
			int r=len+l-1;
			if(vis_[r]!=vis_[l]||vis[l]>0) continue;
			if(check(l,r)){
				ans++;
				last=r;
				_vis[l]+=1,_vis[r+1]+=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}

