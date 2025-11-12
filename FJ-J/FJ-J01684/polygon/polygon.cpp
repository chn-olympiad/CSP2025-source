#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[50005],ax,um,ans,cnt,i;
void dfs(int x,int p,int ax,int um){
	if(x>=i){
		if(um>2*ax){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int j=p+1;j<=n;j++){
		dfs(x+1,j,max(ax,a[j]),um+a[j]);
	}
}
signed main(){
	//freopen("polygon1.in","r",stdin);
	//freopen("polygon1.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ax=max(ax,a[i]);
		um+=a[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(2*ax<um){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(ax==1){
		for(int i=3;i<=n;i++){
			int x=1;
			for(int j=n;j>=n-i+1;j--){
				x*=j;
			}
			for(int j=i;j>=1;j--){
				x/=j;
			}
			x%=998244353;
			ans+=x;
			ans%=998244353;
		}
		cout<<ans;
	}else{
		for(i=3;i<=n;i++){
			dfs(0,0,0,0);
			cnt%=998244353;
		}
		cout<<cnt;
	}
} 
