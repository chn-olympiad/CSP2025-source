#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int t,n,mi,ans,cnt;
int a[N][3],num[3];
int b[N],pos[N];
void solve(){
	cin>>n;
	ans=cnt=num[0]=num[1]=num[2]=0;
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			num[0]++;
			pos[i]=0;
		}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			num[1]++;
			pos[i]=1;
		}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
			num[2]++;
			pos[i]=2;
		}
		ans+=max({a[i][0],a[i][1],a[i][2]});
	}
	if(max({num[0],num[1],num[2]})<=n/2){
		cout<<ans<<"\n";
		return ;
	}
    if(num[0]>num[1]&&num[0]>num[2]) mi=0;
    else if(num[1]>num[0]&&num[1]>num[2]) mi=1;
    else if(num[2]>num[1]&&num[2]>num[0]) mi=2;
    for(int i=1;i<=n;i++){
    	int ma=0;
    	if(pos[i]!=mi) continue;
    	for(int j=0;j<3;j++) if(j!=mi) ma=max(ma,a[i][j]);
        b[++cnt]=a[i][mi]-ma;
	}
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;i++){
		ans-=b[i];
		num[mi]--;
		if(num[mi]<=n/2) break;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) solve();
}

