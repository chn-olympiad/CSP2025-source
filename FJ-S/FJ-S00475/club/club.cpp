#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e5+5;
int a[maxn][4];
int b[maxn][4];
int cnt;
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,greater<pair<pair<int,int>,int> > > q;
signed main(){
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		while(!q.empty()){
			q.pop();
		}
		int n,ans=0;
		int tot1=0,tot2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				tot1++,ans+=a[i][1],b[i][3]=1;
				b[i][1]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				b[i][2]=1;
				if(a[i][2]==a[i][3]) b[i][2]=0;
			}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				tot2++,ans+=a[i][2],b[i][3]=2;
				b[i][1]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				b[i][2]=1;
				if(a[i][1]==a[i][3]) b[i][2]=0;
			}else{
				ans+=a[i][3],b[i][3]=3;
				b[i][1]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				b[i][2]=1;
				if(a[i][1]==a[i][2]) b[i][2]=0;
			}
		}
		if(tot1*2<=n && tot2*2<=n && n<=tot1*2+tot2*2){
			cout<<ans<<"\n";
			continue;
		}
		int maxk,maxx=max(max(tot1,tot2),n-tot1-tot2);
		if(tot1>tot2 && tot1>n-tot1-tot2) maxk=1;
		else if(tot2>tot1 && tot2>n-tot1-tot2) maxk=2;
		else maxk=3;
		for(int i=1;i<=n;i++){
			if(b[i][3]==maxk) q.push(make_pair(make_pair(b[i][1],b[i][2]),i));
		}
		while(maxx*2>n){
			int x=q.top().second;
			q.pop();
			maxx--;
			ans-=b[x][1];
			if(maxk==1){
				if(b[x][2]<1){
					if(tot2<n-tot1-tot2){
						tot2++,tot1--,b[x][3]=2;
					}else{
						tot1--,b[x][3]=3;
					}
					continue;
				}
				if(a[x][1]-a[x][2]==b[x][1]){
					b[x][3]=2;
					tot1--,tot2++;
				}else{
					b[x][3]=3;
					tot1--;
				}
			}else if(maxk==2){
				if(b[x][2]<1){
					if(tot1<n-tot1-tot2){
						tot1++,tot2--,b[x][3]=1;
					}else{
						tot2--,b[x][3]=3;
					}
					continue;
				}
				if(a[x][2]-a[x][1]==b[x][1]){
					b[x][3]=1;
					tot2--,tot1++;
				}else{
					b[x][3]=3;
					tot2--;
				}
			}else{
				if(b[x][2]<1){
					if(tot1<tot2){
						tot1++,b[x][3]=1;
					}else{
						tot2++,b[x][3]=2;
					}
					continue;
				}
				if(a[x][3]-a[x][1]==b[x][1]){
					b[x][3]=1;
					tot1++;
				}else{
					b[x][3]=2;
					tot2++;
				}
			}
		}
		if(tot1*2<=n && tot2*2<=n && n<=tot1*2+tot2*2){
			cout<<ans<<"\n";
			continue;
		}
		int maxp=maxk,minx=1e9;
		if(tot1>tot2 && tot1>n-tot1-tot2) maxk=1;
		else if(tot2>tot1 && tot2>n-tot1-tot2) maxk=2;
		else maxk=3;
		for(int i=1;i<=n;i++){
			if(b[i][3]==maxk){
				if(maxk!=1 && maxp!=1) minx=min(minx,a[i][maxk]-a[i][1]);
				else if(maxk!=2 && maxp!=2) minx=min(minx,a[i][maxk]-a[i][2]);
				else minx=min(minx,a[i][maxk]-a[i][3]);
			}
		}
		cout<<ans-minx<<"\n";
	}
	return 0;
}
