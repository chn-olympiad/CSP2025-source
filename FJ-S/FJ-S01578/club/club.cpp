#include<bits/stdc++.h>
#define int long long
#define INF 1e16
using namespace std;
const int N=1e5+10;
int a[N][4],bl[N],num[N];
int b[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,ans=0;
		num[1]=num[2]=num[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			int t=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=t;
			if(t==a[i][1]){
				bl[i]=1;
				num[1]++;
			}
			else if(t==a[i][2]){
				bl[i]=2;
				num[2]++;
			}
			else{
				bl[i]=3;
				num[3]++;
			}
		}
		int ned=n/2,m=0,add=0;
		if(num[1]>ned){
			add=num[1]-ned;
			for(int i=1;i<=n;i++){
				if(bl[i]!=1){
					continue;
				}
				b[++m]=a[i][1]-max(a[i][2],a[i][3]);
			}
		}
		else if(num[2]>ned){
			add=num[2]-ned;
			for(int i=1;i<=n;i++){
				if(bl[i]!=2){
					continue;
				}
				b[++m]=a[i][2]-max(a[i][1],a[i][3]);
			}
		}
		else{
			add=num[3]-ned;
			for(int i=1;i<=n;i++){
				if(bl[i]!=3){
					continue;
				}
				b[++m]=a[i][3]-max(a[i][1],a[i][2]);
			}
		}
		if(m>0){
			sort(b+1,b+1+m);
		}
		for(int i=1;i<=add;i++){
			ans-=b[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
