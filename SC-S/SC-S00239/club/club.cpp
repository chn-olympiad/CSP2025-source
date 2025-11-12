#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
const int N=5e5+6;
struct node{
	int x,id;
}a[N][4];
bool cmp(node u,node v){
	return u.x>v.x;
} 
bool cmp1(int u,int v){
	return a[u][1].x-a[u][2].x<a[v][1].x-a[v][2].x;
} 
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		vector<int> knt[5];
		f(i,1,n)cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
		f(i,1,n)f(j,1,3)a[i][j].id=j;
		int ans=0;
		f(i,1,n)sort(a[i]+1,a[i]+1+3,cmp);
		f(i,1,n){knt[a[i][1].id].push_back(i);ans+=a[i][1].x;}
		//cout<<"? "<<ans<<"\n"; 
		if(knt[1].size()>n/2){
			sort(knt[1].begin(),knt[1].end(),cmp1);
			int de=0;for(int u: knt[1]){
				ans-=(a[u][1].x-a[u][2].x);de++;
				if(knt[1].size()-de<=n/2){break;}
			}
		}if(knt[2].size()>n/2){
			sort(knt[2].begin(),knt[2].end(),cmp1);
			int de=0;for(int u:knt[2]){
				ans-=(a[u][1].x-a[u][2].x);de++;
				if(knt[2].size()-de<=n/2){break;}
			}
		}if(knt[3].size()>n/2){
			sort(knt[3].begin(),knt[3].end(),cmp1);
			int de=0;for(int u:knt[3]){
				ans-=(a[u][1].x-a[u][2].x);de++;
				if(knt[3].size()-de<=n/2){break;}
			}
		}cout<<ans<<"\n";  
	} 
} 