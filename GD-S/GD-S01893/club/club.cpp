#include<iostream>
#include<algorithm>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
int a[N][5],st[N];
int c[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=2;i++)c[i]=0;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxx=max(max(a[i][0],a[i][1]),a[i][2]);
			if(maxx==a[i][0])c[0]++;
			else if(maxx==a[i][1])c[1]++;
			else c[2]++;
			ans+=maxx;
		}
		int mx=0;
		for(int i=1;i<=2;i++)if(c[mx]<c[i])mx=i;
		if(c[mx]<=n/2){
			cout<<ans<<endl;
			continue;
		}
		int m=0;
		for(int i=1;i<=n;i++){
			if(max(max(a[i][0],a[i][1]),a[i][2])!=a[i][mx])continue;
			int p=1e18;
			for(int j=0;j<=2;j++){
				if(j==mx)continue;
				p=min(p,a[i][mx]-a[i][j]);
			}
			st[++m]=p;
		}
		sort(st+1,st+1+m);
		for(int i=1;i<=c[mx]-n/2;i++)ans-=st[i];
		cout<<ans<<endl;
	}
}

