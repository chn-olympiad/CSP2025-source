#include<bits/stdc++.h>
#define psb push_back
#define fi first
#define se second
#define endl '\n'
using namespace std;
const int N=1e5+5;
int t,n,a[N][3],cnt[3],p[N],mx[N],val[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			mx[i]=max({a[i][0],a[i][1],a[i][2]});
			ans+=mx[i]; 
			for(int j=0;j<3;j++){
				if(a[i][j]==mx[i]){
					cnt[j]++,p[i]=j;
					break;
				}
			}
		}
		for(int i=0;i<3;i++){
			if(cnt[i]>n/2){
				int tot=0;
				for(int j=1;j<=n;j++){
					if(p[j]==i){
						int mx2=0;
						for(int k=0;k<3;k++)
							if(k!=i)mx2=max(mx2,a[j][k]);
						val[++tot]=mx2-mx[j];
					}
				}
				sort(val+1,val+1+tot,greater<>());
				for(int j=1;j<=cnt[i]-n/2;j++)ans+=val[j];
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
