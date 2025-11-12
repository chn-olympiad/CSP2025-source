#include<bits/stdc++.h>
using namespace std;
int a[50005],n,b[50005],r,mod=998244353;
int cmp(int x,int y){
	return x<y;
}
void dfs(int sum,int sheep,int ans,int cnt,int t){
	if(sheep==sum){
		if(ans>cnt*2){
			//c[ans]++;
			//cout<<ans<<" "<<cnt<<endl;
			r++;
		}
		return;
	}
	int o=cnt;
	for(int i=t;i<=n;i++){
		if(b[i]==1&&a[i]>=cnt){
			b[i]=0;
			sheep++;
			ans+=a[i];
			cnt=max(cnt,a[i]);
			//cout<<a[i]<<"+";
			dfs(sum,sheep,ans,cnt,t+1);
			//cout<<r<<endl;
			cnt=o;
			ans-=a[i];
			sheep--;
			b[i]=1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0,1);
	}
	//dfs(3,0,0,0,1);
	cout<<r%mod;
	return 0;
} 
