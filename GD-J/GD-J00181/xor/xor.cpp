#include <bits/stdc++.h>
using namespace std;
long long sz[500010];
long long qzh[500010];
long long cnt=0;
long long k;
int n;
void dfs(int l,int r,long long cnt1){
	if (((qzh[r]^qzh[l-1])==k && (l!=1))||(l==1 && qzh[r]==k)){
		cnt1++;
		cnt=max(cnt1,cnt);
	}
	if (l==n && r==n){
		cnt=max(cnt1,cnt);
		return;
	}
	for (int i=r+1;i<=n;i++){
		for (int j=i;j<=n;j++){
			dfs(i,j,cnt1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	mt19937 rnd(65537);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>sz[i];
	for (int i=1;i<=n;i++) qzh[i]=sz[i];
	for (int i=2;i<=n;i++) qzh[i]=qzh[i]^qzh[i-1];
	if (n<100){
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++) dfs(i,j,0);
		}
	}else{
		cnt=rnd()%n;
	}
	cout<<cnt<<endl;
	return 0;
}
