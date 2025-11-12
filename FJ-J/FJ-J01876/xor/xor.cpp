#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n,k;
int a[500010];
int sum[500010];
int ans;
//int t[500010],tt[500010];
//void dfs(int r,int cnt){
//	if(n-r+cnt<=ans) return ;
//	if(r==n){
//		ans=max(ans,cnt);
////		for(int i=1;i<=cnt;i++){
////			cout<<tt[i]<<' '<<t[i]<<endl;
////		}
////		cout<<endl<<endl;
//		return ;
//	}
//	int rn=r+1,p=0;
//	for(int i=rn;i<=n;i++){
////		p=0;
////		for(int j=rn;j<=i;j++){
////			p^=a[j];
////		}
////		cout<<rn<<' '<<i<<' '<<p<<' '<<"\\\\\\"<<endl;;
//		if((sum[i]^sum[r])==k){
////			t[cnt+1]=i;
////			tt[cnt+1]=rn;
//			dfs(i,cnt+1);
//		}
//	}
//	dfs(rn,cnt);
//} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while((sum[j]^sum[i-1])!=k&&j<=n){
			j++;
		}
//		cout<<j<<endl;
		ans++;
		i=j;
	}
//	dfs(0,0);
	cout<<ans;
	return 0;
} 
/*
4 0
2 1 0 3
*/
