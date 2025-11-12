#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int t,n,a[N][4],p[N],b[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>t;
	while(t--){
		cin >>n;
		int ans=0,tot=0,x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			cin >>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=max(a[i][2],a[i][3]))p[i]=1,x++,ans+=a[i][1];
			else if(a[i][2]>=max(a[i][1],a[i][3]))p[i]=2,y++,ans+=a[i][2];
			else p[i]=3,z++,ans+=a[i][3];
		}
		if(x>n/2){
			for(int i=1;i<=n;i++)if(p[i]==1)b[++tot]=max(a[i][2],a[i][3])-a[i][1];
		}else if(y>n/2){
			for(int i=1;i<=n;i++)if(p[i]==2)b[++tot]=max(a[i][1],a[i][3])-a[i][2];
		}else{
			for(int i=1;i<=n;i++)if(p[i]==3)b[++tot]=max(a[i][2],a[i][1])-a[i][3];
		}
		sort(b+1,b+1+tot,cmp);
		if(x>n/2)for(int i=1;i<=x-n/2;i++)ans+=b[i];
		if(y>n/2)for(int i=1;i<=y-n/2;i++)ans+=b[i];
		if(z>n/2)for(int i=1;i<=z-n/2;i++)ans+=b[i];
		cout <<ans<<"\n";
	}
	return 0;
}
