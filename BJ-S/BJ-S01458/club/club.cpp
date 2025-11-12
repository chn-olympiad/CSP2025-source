#include<bits/stdc++.h>
#define N 100005
#define pb push_back
#define int long long
using namespace std;
int T,n,ans,tmp[5];
struct node{
	int a1,a2,a3;
	int mmax,mid;
}a[N];
vector<node>clubs[5];
bool cmp(node a,node b){return a.mmax-a.mid<b.mmax-b.mid;}	
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		clubs[0].clear();
		clubs[1].clear();
		clubs[2].clear();
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].mmax=max(a[i].a1,max(a[i].a2,a[i].a3));
			tmp[0]=a[i].a1;tmp[1]=a[i].a2;tmp[2]=a[i].a3;
			sort(tmp,tmp+3);
			a[i].mid=tmp[1];
			if(a[i].mmax==a[i].a1){
				clubs[0].pb(a[i]);
			}else if(a[i].mmax==a[i].a2){
				clubs[1].pb(a[i]);
			}else{
				clubs[2].pb(a[i]);
			}
			ans+=a[i].mmax;
		}
		for(int i=0;i<3;i++){
			if(clubs[i].size()>n/2){
				sort(clubs[i].begin(),clubs[i].end(),cmp);
				for(int j=0;j<clubs[i].size();j++){
					if(clubs[i].size()-j<=n/2)break;
					ans-=clubs[i][j].mmax;
					ans+=clubs[i][j].mid;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
