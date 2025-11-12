#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
LL n,t,a[N][5],ans,b[N],c[N],cnti,cntj,cntk;
bool fla=1,flb=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0) fla=0;
			if(a[i][3]!=0) flb=0;
		}
		if(n==2){
			ans=max(a[1][1]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][1],max(a[1][2]+a[2][3],max(a[1][3]+a[2][1],a[1][3]+a[2][2])))));
			cout<<ans<<endl;
			continue;
		}
		if(fla&&flb){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
