#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,k,aaa,cnt;
int a[4][N];
struct node{
	int jz,id,zs;
};
bool cmp(node x,node y){
	return x.jz>y.jz;
}
void dfs(int x,int t_1,int t_2,int t_3,int sum){
//	cout<<x<<" "<<sum<<"\n";
	if(x>n){
		cnt=max(cnt,sum);
		return;
	}
	if(t_1<k) dfs(x+1,t_1+1,t_2,t_3,sum+a[1][x]);
	if(t_2<k) dfs(x+1,t_1,t_2+1,t_3,sum+a[2][x]);
	if(t_3<k) dfs(x+1,t_1,t_2,t_3+1,sum+a[3][x]);
	return;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>t;
	while(t--){
		cnt=0;
		bool f_2=1,f_3=1;
//		set<int> se;
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>aaa;
				if(j==2&&aaa!=0) f_2=0;
				if(j==3&&aaa!=0) f_3=0;
				a[j][i]=aaa;
//				se.insert(aaa);
			}
		}
		k=n/2;
		if(n<=10){
			dfs(0,0,0,0,0);
			cout<<cnt<<"\n";
		}
		else if(f_2&&f_3){
			sort(a[1]+1,a[1]+1+n,greater<int>());
			for(int i=1;i<=k;++i){
				cnt+=a[1][i];
			}
			cout<<cnt<<"\n";
		}
//		else if(f3){
//			
//		}
		else{
			vector<node> ve;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=3;++j){
					ve.push_back({a[j][i],i,j});
				}
			}
			sort(ve.begin(),ve.end(),cmp);
			vector<bool> vis(N,0);
			vector<int> rs(4,0);
			for(int i=0;i<(int)ve.size();++i){
				if(vis[ve[i].id]) continue;
				if(rs[ve[i].zs]>=k) continue;
				cnt+=ve[i].jz;
				++rs[ve[i].zs];
				vis[ve[i].id]=1;
				
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
