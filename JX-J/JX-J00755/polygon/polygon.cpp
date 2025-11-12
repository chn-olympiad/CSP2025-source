#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
long long n,a[10000],ans,f;
void dfs(long long gs,long long bh,long long sum,long long maxx){
	if(gs>=3&&sum>2*maxx){
		ans++;
		ans%=N;
		long long fm=1,fz=1,cnt=0;
		for(int i=n-bh;i>=1;i--){
			cnt++;
			fz*=i;
			fm*=cnt;
			ans+=(fz/fm);
			ans%=N;
		}
		return;
	}
	int gg;
	if(gs>=3)gg=2;
	else gg=gs;
	for(int i=bh+1;i<=n-(3-gg)+1;i++){
		dfs((long long)gs+1,(long long)i,sum+a[i],max(maxx,a[i]));
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	/*if(f==0){
		long long fz=1,fm=1,cnt=0;
		for(int i=n;i>=1;i--){
			cnt++;
			fz*=i;
			fm*=cnt;
			if(i<=n-3){
				ans+=(fz/fm);
				ans%=N;
			}
		}
		cout<<ans;
		return 0;
	}*/
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-3+1;i++){
		dfs(1,i,a[i],a[i]);
	}
	cout<<ans%N;
	return 0;
}
