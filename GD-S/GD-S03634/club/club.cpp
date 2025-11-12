#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+4;
const int T=4;
ll t,n,ans,c[T],b[T],m[T][N],a[N][T];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=3;i++){
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				b[1]=1;
				if(a[i][2]>=a[i][3]){
					b[2]=2;
					b[3]=3;
				}else{
					b[2]=3;
					b[3]=2;
				}
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				b[1]=2;
				if(a[i][1]>=a[i][3]){
					b[2]=1;
					b[3]=3;
				}else{
					b[2]=3;
					b[3]=1;
				}
			}else{
				b[1]=3;
				if(a[i][1]>=a[i][2]){
					b[2]=1;
					b[3]=2;
				}else{
					b[2]=2;
					b[3]=1;
				}
			}
			c[b[1]]++;
			m[b[1]][c[b[1]]]=a[i][b[1]]-a[i][b[2]];
			ans+=a[i][b[1]];
		}
		for(int i=1;i<=3;i++){
			if(c[i]>(n>>1)){
				sort(m[i]+1,m[i]+c[i]+1);
				for(int j=1;j<=c[i]-(n>>1);j++){
					ans-=m[i][j];
				}
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
