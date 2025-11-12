#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n;
int a[MAXN][4],v[MAXN],p[4];
struct turn{
	int id,to,d;
};
vector<turn> q[4];
void turn_calc(int x){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			q[i].push_back({x,j,a[x][j]-a[x][i]});
	return ;
}
bool cmp(turn x,turn y){
	return x.d>y.d;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int maxa=0,ans=0;
		p[1]=p[2]=p[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxa=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=maxa;
			if(maxa==a[i][1]) v[i]=1,p[1]++;
			else if(maxa==a[i][2]) v[i]=2,p[2]++;
			else v[i]=3,p[3]++;
			turn_calc(i);
		}
		for(int i=1;i<=3;i++){
			if(p[i]>n/2){
//				printf("(%d,%d)",i,p[i]);
				sort(q[i].begin(),q[i].end(),cmp);
				for(int j=0;j<q[i].size()&&p[i]>n/2;j++)
					if(v[q[i][j].id]==i&&p[q[i][j].to]<n/2){
						v[q[i][j].id]=q[i][j].to;
						p[i]--,p[q[i][j].to]++;
						ans+=q[i][j].d;
					}
			}
		}
		cout<<ans<<"\n";
		q[1].clear();
		q[2].clear();
		q[3].clear();
	}
	return 0;
}