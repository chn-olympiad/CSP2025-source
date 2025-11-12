#include<bits/stdc++.h>
using namespace std;
const int mode=998244353;
long long n,m,a[505],b[505],ans,c[505];
string s;
long long powe(int x){
	long long pow2=1,sh=2;
	while(x>0){
		if(x%2==1){
			pow2=pow2*sh%mode;
		}
		sh=sh*sh%mode;
		x/=2;
	}
	return pow2;
}
void dfs(int h,int shu){
	if(h==n+1 && shu>=m){
		ans=(ans+1)%mode;
		return;
	}
	for(int l=1;l<=n;l++){
		if(b[l]==0){
			b[l]=1;
			if(c[l]>=a[l] || s[h]=='0'){
				dfs(h+1,shu);
			}else{
				dfs(h+1,shu+1);
			}
			b[l]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s="#"+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]+=c[i-1];
		if(s[i]=='0'){
			c[i]++;
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
