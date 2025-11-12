#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL ans=0,sum=0;
int T,n;
const int N=1e5+5;
LL a[N][5],f[5],dp[N][5],b[N];

void dfs(int x,LL sum){
	if(f[1]>n/2||f[2]>n/2||f[3]>n/2) return;
	if(x>n){
		if(f[1]>n/2||f[2]>n/2||f[3]>n/2) return;
		ans=max(ans,sum);
		return;
	}
	
	LL s=sum+a[x][1];
	f[1]++;
	dfs(x+1,s);
	f[1]--;
	
	f[2]++;
	s=sum+a[x][2];
	dfs(x+1,s);
	f[2]--;
	
	f[3]++;
	s=sum+a[x][3];
	dfs(x+1,s);
	f[3]--;
	return;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cin>>n;
		sum=ans=0;
		for(int i=1;i<=n;i++){
			LL maxx=-1;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				maxx=max(maxx,a[i][j]);
			}
			sum+=maxx;
		}
		if(n<=30){
			ans=0;
			dfs(1,0);
			cout<<ans<<endl;
		}
		else{
			int ff=0;
			for(int i=1;i<=n;i++){
				if(a[i][2]==0&&a[i][3]==0) continue;
				else ff=1;
			}
			if(!ff){
				for(int i=1;i<=n;i++) b[i]=a[i][1];
				sort(b+1,b+1+n);
				for(int i=n;i>=n/2;i--) ans+=b[i];
				cout<<ans<<endl;
			}
			else{
				cout<<sum<<endl;
			}
		}
	}
	
	return 0;
}
