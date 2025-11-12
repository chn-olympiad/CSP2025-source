#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100005][4];
ll n;
ll dp[100005][4];
ll bol[4];
ll sum[6];
ll w=1;

void dfs(ll i,ll s){
	if(i>n){
		sum[w]=max(sum[w],s);
		return;
	}
	for(int j=1;j<=3;j++){
		if(bol[j]>0){
			bol[j]--;
			dfs(i+1,s+a[i][j]);
			bol[j]++;
		}
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		bool bol1=true;
		bool bol2=true;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) bol1=false;
			if(a[i][3]!=0) bol2=false;
		}
		if(bol1){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i][1]<a[j][1]) swap(a[i][1],a[j][1]);
				}
			}
			for(int i=1;i<=n/2;i++){
				sum[w]+=a[i][1];
			}
			w++;
			continue;
		}
		if(bol2){
			bol[1]=bol[2]=bol[3]=n/2;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(max(a[i][1],a[i][2])<max(a[j][1],a[j][2])){
						swap(a[i][1],a[j][1]);
						swap(a[i][2],a[j][2]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]&&bol[1]>0){
					sum[w]+=a[i][1];
					bol[1]--;
				}else{
					sum[w]+=a[i][2];
					bol[2]--;			
				}
			}
			w++;
			continue;				
		}
		bol[1]=bol[2]=bol[3]=n/2;
		for(int i=1;i<=3;i++){
			bol[i]--;
			dfs(2,a[1][i]);
			bol[i]++;
		}
		w++;
	}
	for(ll i=1;i<w;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
} 
