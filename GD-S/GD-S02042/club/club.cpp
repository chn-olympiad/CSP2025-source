#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,a[N][5],id_mx[N],lt[N],num[5],x[N],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		memset(num,0,sizeof num);
		memset(x,0,sizeof x);
		memset(a,0,sizeof a);
		memset(id_mx,0,sizeof id_mx);
		memset(lt,0,sizeof lt);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				id_mx[i]=1;
				lt[i]=a[i][1]-max(a[i][2],a[i][3]);
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				id_mx[i]=2;
				lt[i]=a[i][2]-max(a[i][1],a[i][3]);
			}
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				id_mx[i]=3;
				lt[i]=a[i][3]-max(a[i][2],a[i][1]);
			}
			num[id_mx[i]]++;
		}
		//cout<<num[1]<<" "<<num[2]<<" "<<num[3];
		int tot=0;
		for(int i=1;i<=n;i++) ans+=a[i][id_mx[i]]; 
		for(int i=1;i<=3;i++){
			if(num[i]>n/2){
				for(int j=1;j<=n;j++){
					if(id_mx[j]==i) x[++tot]=lt[j];
				}
				sort(x+1,x+1+tot);
				for(int j=1;j<=num[i]-n/2;j++) ans-=x[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

