#include<bits/stdc++.h>

using namespace std;

int n;
int a[5005];
int m;
int ans;

void dfs(int x,int cnt,int sum,int mx){
	if(cnt==1){
	//	cout<<x<<" "<<sum<<" "<<mx<<endl<<endl;
		if(sum>mx*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=x+1;i<=n-cnt+2;i++){
	//	cout<<x<<" "<<i<<endl;
		dfs(i,cnt-1,sum+a[i],max(mx,a[i]));
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
		//	cout<<i<<" "<<j<<endl<<endl<<endl;
			dfs(j,i,a[j],a[j]);
		}
	}
	
	cout<<ans%998244353;
	
	return 0;
}
