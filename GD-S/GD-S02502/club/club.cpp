#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N],c[N],v,v1,v2,ans,sum;
void dfs(int x){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(v<n/2){
		v++;
		sum+=a[x];
		dfs(x+1);
		sum-=a[x];
		v--;
	}
	if(v2<n/2){
		v2++;
		sum+=b[x];
		dfs(x+1);
		sum-=b[x];
		v2--;
	}
	if(v1<n/2){
		v1++;
		sum+=c[x];
		dfs(x+1);
		sum-=c[x];
		v1--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
