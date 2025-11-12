#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,c[500],ans,ycg,ez,cd,js;
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>cd;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int k=1;k<=n-1;k++){
		for(int j=k;j<=n-1;j++){
			swap(c[j],c[j+1]);
			ycg=0;ans=0;js=1;
			for(int i=1;i<=n;i++){
				if(cd/js%10==0 or ycg>=c[i]) ycg++;
				else ans++;
				js*=10;
			}
			if(ans>=m) ez=(++ez-1)%998224353+1;
		}
	}
	cout<<ez;
	return 0;
}

