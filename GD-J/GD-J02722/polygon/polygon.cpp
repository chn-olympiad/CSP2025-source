#include<bits/stdc++.h>
using namespace std;
#define int long long
/* i am really want to ak!*/
const long long mod = 998244353;
int n;
int f[100005];
int stutus[100005];
bool flag = 1;
int ans =0;
int a(int xx,int yy){
	int ans = 1;
	for(int i=yy;i>yy-xx;i--){
		ans *= i;
	}
	return ans;
}
int c(int x,int y){
	return a(x,y) / a(x,x)%mod;
}
bool check(int axt[],int xt){
	int sum = 0;
	for(int i=1;i<xt-1;i++){
//		cout<<axt[i]<<" ";
		sum += f[axt[i]];
	}
	return sum>f[axt[xt-1]];
}
void dfs(int size,int start,int a[],int xb){
//	cout<<size<<" ";
	if(start+size-1 > n) return ;
	if(size<=0){/*cout<<endl;*/
		if(check(a,xb)){
//			cout<<1<<" ";
			
			ans = (ans+1)%mod;
		}
		return ;
	}
	for(int i=start+1;i<=n;i++){
		if(stutus[i] == 0){
			a[xb++] = i;
			stutus[i] = 1;
			dfs(size-1,i,a,xb);
			stutus[i] = 0;
			a[--xb] = 0;
		}
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(f[i] != 1) flag = 0;
	}
	if(flag){
		int sum = 0;
		for(int i=3;i<=n;i++){
			sum = (sum+c(i,n))%mod;
		}
		cout<<sum % mod;
	}else{
		for(int i=3;i<=n;i++){
			for(int startt = 1;startt<=n-i+1;startt++){
				int ax[100001]={};
				memset(ax,0,sizeof(ax));
				memset(stutus,0,sizeof(stutus));
				dfs(i,startt,ax,1);
			}
			
		}
//		cout<<endl;
//cout<<endl;
		cout<<ans%mod;
	}
	return 0;
}

