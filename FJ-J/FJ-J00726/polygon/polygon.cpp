#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
int cnt,kk[5001];
int mod=998244353;
bool v[5001];
void dfs(int x,int y,int m,int k,int l){
	if(y==x){
		if(m>k*2){
			ans++;
			ans%=mod;
//			for(int i=1;i<=cnt;i++){
//				cout<<kk[i]<<' ';
//			}
//			cout<<m<<' '<<k<<' ';
//			cout<<'\n';
		}
		return;
	}
	for(int i=l+1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
//			kk[++cnt]=i;
			dfs(x,y+1,m+a[i],a[i],i);
			v[i]=0;
//			cnt--;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
//		cout<<a[i]<<"<";
		dfs(i,0,0,0,0);
	}
	cout<<ans;
	return 0;
}//ATLETICO MADRID
