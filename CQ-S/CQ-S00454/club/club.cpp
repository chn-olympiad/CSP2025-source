#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,loc[N],cnt[3],b[N];
struct node{
	int x,id;
	bool operator < (node aa) const{
		return x>aa.x;
	}
}a[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<3;i++)cnt[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j].x;a[i][j].id=j;
			}
			sort(a[i],a[i]+3);
			loc[i]=a[i][0].id;cnt[a[i][0].id]++;
			ans+=a[i][0].x;
		}
		int lim=n/2;
		if(cnt[0]<=lim&&cnt[1]<=lim&&cnt[2]<=lim){
			cout<<ans<<'\n';
		}
		else{
			int need=0,len=0;
			for(int i=0;i<3;i++){
				if(cnt[i]>lim){
					need=cnt[i]-lim;
					for(int j=1;j<=n;j++){
						if(a[j][0].id==i){
							b[++len]=a[j][0].x-a[j][1].x;
						}
					}
				}
			}
			sort(b+1,b+len+1);
			for(int i=1;i<=need;i++){
				ans-=b[i];
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
