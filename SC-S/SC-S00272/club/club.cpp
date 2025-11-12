#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll a[N][3],b[N][3],id[N];
priority_queue<pair<ll,ll> > q;
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int mx=-1e8;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>mx){
				mx=a[i][j];
				id[i]=j;
			}
			b[i][j]=a[i][j];

		}
		sort(b[i]+1,b[i]+1+3);
		q.push(make_pair(b[i][3]-b[i][2],i));		
		
	}
	/*for(int i=1;i<=n;i++){
		cout<<id[i]<<" ";
		for(int j=1;j<=3;j++){
			//cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}*/
	ll suma=0,sumb=0,sumc=0,ans=0;
	while(q.size()){
		int x=q.top().second;
		q.pop();

		if(id[x]==1){
			suma++;
		}
		if(id[x]==2){
			sumb++;
		}
		if(id[x]==3){
			sumc++;
		}
	//	cout<<suma<<" "<<sumb<<" "<<sumc<<n/2<<" "<<endl;
		if(suma>n/2){
		
		//	cout<<x<<" "<<b[x][2]<<endl;
			ans+=b[x][2];
			suma--;
			continue;
			
		}
		if(sumb>n/2){
		//	cout<<x<<" "<<b[x][2]<<endl;
			ans+=b[x][2];
			sumb--;
			continue;
			
		}
		if(sumc>n/2){
		//	cout<<x<<" "<<b[x][2]<<endl;
			ans+=b[x][2];
			sumc--;
			continue;
			
		}
		//cout<<x<<" "<<b[x][3]<<endl;
		ans+=b[x][3];
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}