#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long n,q=0,ans=0;
void dfs(int x,int p,int cmp,int li,int ma){
	if(cmp==li){
		if(x>=2*ma){
			ans++;
		}
		return;
	}
	for(int i=p-1;i>=li-cmp;i--){
		if((li-cmp)*a[i]>(2*ma)-x){
			dfs(x+a[i],i,cmp+1,li,ma);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)q=1;
	}
	if(q==0){
		ans=1;
		for(int i=3;i<=n;i++){
			long long x=1,y=1;
			if(i>n/2){
				for(int j=0;j<n-i;j++){
					x*=n-j;
					y*=(j+1);
				}
			}
			else{
				for(int j=0;j<i;j++){
					x*=n-j;
					y*=(j+1);
				}
			}
			ans+=(x/y)%998244353;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=n;j>=i;j++){
			dfs(a[j],j,1,i,a[j]*2);
		}
	}
	cout<<ans;
	return 0;
} 
