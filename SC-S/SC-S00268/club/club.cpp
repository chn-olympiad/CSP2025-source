#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[3];
const int N=1e5+10;
struct jgt{
	int right,mid;
	int rbn,mbn;
	//int last,lbn;
}sz[N];
int T,n,a[N][5];
int tong[5],ans;
int cmp(jgt a,jgt b){
	return a.right>b.right;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		tong[1]=tong[2]=tong[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][1]>a[i][2] and a[i][1]>a[i][3]){
				sz[i].right=a[i][1];
				sz[i].rbn=1;
			}
			else if(a[i][2]>a[i][1] and a[i][2]>a[i][3]){
				sz[i].right=a[i][2];
				sz[i].rbn=2;
			}
			else{
				sz[i].right=a[i][3];
				sz[i].rbn=3;
			}
			
			if(sz[i].rbn!=1 and a[i][1]>a[i][3] or sz[i].rbn!=1 and a[i][1]>a[i][2]){
				sz[i].mid=a[i][1];
				sz[i].mbn=1;
			}
			else if(sz[i].rbn!=2 and a[i][2]>a[i][3] or sz[i].rbn!=2 and a[i][2]>a[i][1]){
				sz[i].mid=a[i][2];
				sz[i].mbn=2;
			}
			else{
				sz[i].mid=a[i][3];
				sz[i].mbn=3;
			}
			
//			if(sz[i].rbn!=1 and sz[i].mbn!=1){
//				sz[i].last=a[i][1];
//				sz[i].lbn=1;
//			}
//			else if(sz[i].rbn!=2 and sz[i].mbn!=2){
//				sz[i].last=a[i][2];
//				sz[i].lbn=2;
//			}
//			else{
//				sz[i].last=a[i][3];
//				sz[i].lbn=3;
//			}
		}
		sort(sz+1,sz+1+n,cmp);
		for(int i=1;i<=n;i++){
			if( (tong[sz[i].rbn]+1)<=(n/2) ){
				tong[sz[i].rbn]++;
				ans+=sz[i].right;
				q[sz[i].rbn-1].push({sz[i].right-sz[i].mid,i});
			}
			else if(q[sz[i].rbn-1].size()){
				int f=q[sz[i].rbn-1].top().first;
				int s=q[sz[i].rbn-1].top().second;
				if(sz[i].right>f){
					tong[sz[i].mbn]++;
					q[sz[i].rbn-1].pop();
					ans+=(sz[i].right-f);
					q[sz[i].rbn-1].push({sz[i].right-sz[i].mid,i});
				}
				else{
					tong[sz[i].mbn]++;
					ans+=sz[i].mid;
				}
			}
			else{
				tong[sz[i].mbn]++;
				ans+=sz[i].mid;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 