#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define ll long long
#define db long double
#define endl '\n'
using namespace std;
const int MAXN=1e5+5,MAXM=0,MOD=0;
const long long INF=(1ll<<62);
ll T=1,n,a[MAXN][4];
ll num[4][MAXN],tot[4];
ll val[MAXN],ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>T;
	while (T--){
		cin>>n;
		ans=tot[1]=tot[2]=tot[3]=0;
		for (int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for (int i=1;i<=n;i++){
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			if (a[i][1]==max(max(a[i][1],a[i][2]),a[i][3])) num[1][++tot[1]]=i;
			else if (a[i][2]==max(max(a[i][1],a[i][2]),a[i][3])) num[2][++tot[2]]=i;
			else if (a[i][3]==max(max(a[i][1],a[i][2]),a[i][3])) num[3][++tot[3]]=i;
		}
		if (max(tot[1],max(tot[2],tot[3]))>n/2){
			ll I=0;
			for (int i=1;i<=3;i++) if (tot[i]>tot[I]) I=i;
			for (int i=1;i<=tot[I];i++){
				val[i]=0;
				for (int j=1;j<=3;j++){
					if (j!=I) val[i]=max(val[i],a[num[I][i]][j]);
				}
				val[i]-=a[num[I][i]][I];
			}
			sort(val+1,val+1+tot[I]);
			for (int i=tot[I];i>(n/2);i--) ans+=val[i];
			cout<<ans<<endl;
		}
		else cout<<ans<<endl;
	}
}

