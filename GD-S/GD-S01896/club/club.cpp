#include <bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int T,n,m,ans,cnt,num[4],val[maxn],bel[maxn],a[maxn][4];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ans=cnt=0;
		num[1]=num[2]=num[3]=0;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]) bel[i]=1;
			else bel[i]=2;
			if(a[i][3]>=a[i][bel[i]]) bel[i]=3;
			num[bel[i]]++;ans+=a[i][bel[i]];
		}
		if(num[1]>=num[2]) m=1;
		else m=2;
		if(num[3]>=num[m]) m=3;
		if(num[m]>n/2){
			for(int i=1;i<=n;i++){
				if(bel[i]==m){
					int p=0x3f3f3f3f;
					for(int j=1;j<=3;j++){
						if(j==m) continue;
						p=min(p,a[i][m]-a[i][j]);
					}
					val[++cnt]=p;
				}
			}
			sort(val+1,val+cnt+1);
			for(int i=1;i<=cnt-n/2;i++) ans-=val[i];
		}
		cout<<ans<<"\n";
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
} 
