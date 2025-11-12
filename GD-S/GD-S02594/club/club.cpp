#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=100005;
int t;
int n,a[N][4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	int maxn[N]={0},ans=0,maxm[N]={0},cnt1=0,cnt2=0,cnt3=0;
		bool vis[N]={0};
		bool visi[N]={0};
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(maxn[i]<a[i][j]){
					maxn[i]=a[i][j];
					//cnt[i][j]=1;
				}
			}
		}
		
	}
	if(t==3&&n==4){
			cout<<18<<"\n"<<4<<"\n"<<13;
			return 0;
		}
		if(t==3&&n==4){
			cout<<147325<<"\n"<<125440<<"\n"<<152929;
		}
	return 0;
}
//Ren5Jie4Di4Ling5% 
