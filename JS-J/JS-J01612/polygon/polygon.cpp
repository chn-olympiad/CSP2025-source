#include<bits/stdc++.h>
using namespace std;
long long c[5001][5001];
int a[5001],tool[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,mx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		long long ans=0;
		c[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=i;j++){
				if(j==0) c[i][j]=1;
				else c[i][j]=c[i-1][j]+c[i-1][j-1];
				c[i][j]%=998244353;
			}	
		for(int i=3;i<=n;i++){
			ans+=c[n][i];
			ans%=998244353;
		}
		cout<<ans;
	}
	else{
		long long ans=0;
		int cnt=0;
		for(int i=1;i<(1<<n);i++){
			cnt=0;
			for(int j=1;j<=n;j++) if(i>>(j-1)&1) tool[++cnt]=a[j];
			if(cnt<=2) continue;
			sort(tool+1,tool+cnt+1);
			int sum=0;
			for(int j=1;j<cnt;j++) sum+=tool[j];
			if(sum>tool[cnt]) ans++;
		}
		cout<<ans%998244353;
	}
    return 0;
}
