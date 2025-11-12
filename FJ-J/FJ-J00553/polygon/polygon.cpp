#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n;
int a[5009];
long long ans;
int tnum;
//void dfs(int xb,int maxn,int nq,int trn,int tnum,bool qi) { //nq已经扔了几个 trn目标扔几个  tnum目前总和,qi这个取不取
//	if(nq >= trn) {
//		int temp = maxn*2;
//		temp-=tnum;
//		if(temp>0) {
//			ans++;
//		}
//		return;
//	}printf("%d %d %d %d %d",xb,maxn,nq,trn,tnum,qi);
//	if(qi) {
//		dfs(xb+1,max(maxn,a[xb]),nq,trn,tnum+a[xb],1);
//		dfs(xb+1,max(maxn,a[xb]),nq+1,trn,tnum+a[xb],0);
//	}else{
//		dfs(xb+1,maxn,nq,trn,tnum,1);
//
//		dfs(xb+1,maxn,nq+1,trn,tnum,0);
//	}
//}
//void dfs(int xb,int ed,bool qi,int maxn,int num) { //ed剩下能扔的个数 qi这个取不取
//	if(xb>n) {
//		if(num>maxn*2) {
//			cout<<ed<<" "<<num<<" "<<maxn<<endl;
//			ans++;
//		}
//		return;
//	}
//	if(qi) {
//		maxn = max(maxn,a[xb]);
//		num+=a[xb];
//	}
//	if(ed>=1){
//		dfs(xb+1,ed-1,0,maxn,num);
//	}
//	dfs(xb+1,ed,1,maxn,num);
//}
//void dfs(int xb,int ed,int num,int maxn){
//	
//}
bool onefl = 0;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1){
			onefl = 1;
		}
//		tnum +=a[i];
	}
	if(n == 3) {
		int maxn = max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>maxn*2) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	}
	if(!onefl){
		ans = n;
		for(int i = 2;i<=n-3;i++){
			long long temp = n;
			for(int j = 1;j<=i;j++){
				temp *=(n-j+1);
			}
			temp/=2;
			temp%=MOD;
			ans+=temp;
			cout<<temp<<endl;
		}
		cout<<ans;
		return 0;
	}
//	for(int i = n-3; i>=0; i--) {
//		dfs(1,i,1,-1,0);
//		if(i>=1){
//			dfs(1,i,0,-1,0);
//		}
//		dfs(1,a[1],0,i,a[1],1);
//		dfs(1,-1,1,i,0,0);
//	}
	cout<<ans%MOD;
	return 0;
}
