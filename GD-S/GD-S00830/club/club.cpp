#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll a[N][4],ans,cha[N];
short x[N];
int t[4];
int n;
void init(){
	memset(t,0,sizeof(t));
	memset(a,0,sizeof(a));
	ans=0;
}
void add(){
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]){
			if(a[i][1]>=a[i][3]) x[i]=1;
			else x[i]=3;
		}else{
			if(a[i][2]>=a[i][3]) x[i]=2;
			else x[i]=3;
		}
		ans+=a[i][x[i]];
		t[x[i]]++;
	}
}
int main(){
	//cout<<1e5*log2(1e5)<<endl;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T;cin>>T;
	while(T--){
		init();
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		add();
		int ni=-1;
		for(int i=1;i<=3;i++){
			if(t[i]>n/2){
				ni=i;
				break;
			}
		}
		
		if(ni==-1) cout<<ans<<endl;
		else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				
				if(x[i]==ni){
					cha[++cnt]=1e18;
					for(int j=1;j<=3;j++){
						if(j!=x[i]) cha[cnt]=min(cha[cnt],a[i][x[i]]-a[i][j]);
					}
				}
			}
			
			sort(cha+1,cha+cnt+1);
			for(int i=t[ni],j=1;i>n/2;i--,j++) ans-=cha[j];
			cout<<ans<<endl;
		}
	}
}
